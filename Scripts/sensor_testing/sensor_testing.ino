#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN_1 10
#define DHT11_PIN_2 9

void setup() {
  Serial.begin(19200);
}

void loop() { 
  DHT.read(DHT11_PIN_1);
  Serial.print("temp_1: ");
  Serial.print(DHT.temperature);
  Serial.print("  humi_1: ");
  Serial.print(DHT.humidity);

  DHT.read(DHT11_PIN_2);
  Serial.print("  temp_2: ");
  Serial.print(DHT.temperature);
  Serial.print("  humi_2: ");
  Serial.println(DHT.humidity);
  delay(1000);
}