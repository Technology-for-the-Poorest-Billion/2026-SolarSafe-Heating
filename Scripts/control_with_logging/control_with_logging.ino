/*
 * SOLARSAFE — fan (BTS7960) + dual DHT11 + CSV serial logging
 * Board: Arduino Nano Every
 * Fan: RPWM=D5, LPWM=D6, R_EN=D7, L_EN=D8
 * DHT11: inlet=D2, outlet=D4
 *
 * Serial 115200
 * CSV rows:  DATA,<ms>,<inlet_T>,<inlet_RH>,<outlet_T>,<outlet_RH>,<fan_%>,<inlet_ok>,<outlet_ok>
 * Commands:  0 OFF, 1 LOW, 2 MED, 3 HIGH, 4 MAX, +/- step 10%, ? help
 */

#include <DFRobot_DHT11.h>

const uint8_t PIN_FAN_RPWM   = 5;
const uint8_t PIN_FAN_LPWM   = 6;
const uint8_t PIN_FAN_REN    = 7;
const uint8_t PIN_FAN_LEN    = 8;
const uint8_t PIN_DHT_INLET  = 2;
const uint8_t PIN_DHT_OUTLET = 4;

uint8_t fanPercent = 0;
unsigned long startMs = 0;

DFRobot_DHT11 dht;

void fanEnable(bool on) {
  digitalWrite(PIN_FAN_REN, on ? HIGH : LOW);
  digitalWrite(PIN_FAN_LEN, on ? HIGH : LOW);
}

void fanSetPercent(uint8_t percent) {
  percent = constrain(percent, 0, 100);
  fanPercent = percent;

  if (percent == 0) {
    analogWrite(PIN_FAN_RPWM, 0);
    analogWrite(PIN_FAN_LPWM, 0);
    fanEnable(false);
    return;
  }

  fanEnable(true);
  analogWrite(PIN_FAN_LPWM, 0);

  if (percent < 40) {
    analogWrite(PIN_FAN_RPWM, 255);
    delay(400);
  }

  uint8_t duty = map(percent, 0, 100, 0, 255);
  analogWrite(PIN_FAN_RPWM, duty);
}

// --- DHT helpers ---
bool readDht(uint8_t pin, float &tempC, float &rhPct) {
  int err = 0;
  dht.read(pin);
  if (err != 0) {
    return false;
  }
  tempC = dht.temperature;
  rhPct = dht.humidity;
  return true;
}

void logCsvRow() {
  float inletT = NAN, inletRH = NAN, outletT = NAN, outletRH = NAN;
  bool inletOk  = readDht(PIN_DHT_INLET,  inletT,  inletRH);
  delay(250);
  bool outletOk = readDht(PIN_DHT_OUTLET, outletT, outletRH);

  Serial.print(F("DATA,"));
  Serial.print(millis() - startMs);
  Serial.print(F(","));

  if (inletOk) {
    Serial.print(inletT, 1);
    Serial.print(F(","));
    Serial.print(inletRH, 1);
  } else {
    Serial.print(F(","));  // empty temp
    Serial.print(F(","));  // empty rh
  }
  Serial.print(F(","));

  if (outletOk) {
    Serial.print(outletT, 1);
    Serial.print(F(","));
    Serial.print(outletRH, 1);
  } else {
    Serial.print(F(","));
    Serial.print(F(","));
  }
  Serial.print(F(","));
  Serial.print(fanPercent);
  Serial.print(F(","));
  Serial.print(inletOk ? 1 : 0);
  Serial.print(F(","));
  Serial.println(outletOk ? 1 : 0);
}

void handleSerialCommand() {
  if (!Serial.available()) {
    return;
  }
  char c = Serial.read();
  switch (c) {
    case '0': fanSetPercent(0);   Serial.println(F("# Fan OFF")); break;
    case '1': fanSetPercent(25);  Serial.println(F("# Fan LOW 25%")); break;
    case '2': fanSetPercent(50);  Serial.println(F("# Fan MED 50%")); break;
    case '3': fanSetPercent(75);  Serial.println(F("# Fan HIGH 75%")); break;
    case '4': fanSetPercent(85);  Serial.println(F("# Fan MAX 85%")); break;
    case '+':
      fanSetPercent(constrain(fanPercent + 10, 0, 100));
      Serial.print(F("# Fan "));
      Serial.print(fanPercent);
      Serial.println(F("%"));
      break;
    case '-':
      fanSetPercent(constrain(fanPercent - 10, 0, 100));
      Serial.print(F("# Fan "));
      Serial.print(fanPercent);
      Serial.println(F("%"));
      break;
    case '?':
      Serial.println(F("# Commands: 0 OFF, 1-4 presets, + - step 10%"));
      break;
    default:
      break;
  }
}

void setup() {
  pinMode(PIN_FAN_RPWM, OUTPUT);
  pinMode(PIN_FAN_LPWM, OUTPUT);
  pinMode(PIN_FAN_REN, OUTPUT);
  pinMode(PIN_FAN_LEN, OUTPUT);

  analogWrite(PIN_FAN_RPWM, 0);
  analogWrite(PIN_FAN_LPWM, 0);
  fanEnable(false);

  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  startMs = millis();

  Serial.println(F("# SOLARSAFE CSV logger started"));
  Serial.println(F("# Keys: 0 OFF  1 LOW  2 MED  3 HIGH  4 MAX  +/- step  ? help"));
  fanSetPercent(0);
}

void loop() {
  handleSerialCommand();
  logCsvRow();
  delay(2000);
}