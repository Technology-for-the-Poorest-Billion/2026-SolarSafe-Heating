---
title: Electronics Design
---

# Electronics Design Report
**Author:** Zac Heggie

This report details the electronics developed for the SolarSafe dehumidifier prototype: the power architecture, the fan drive and control electronics, the sensing arrangement, and the software and data logging pipeline used throughout the experimental setup described in the other two reports.

## System Architecture

Our prototype is designed to be completely compatible with Benard's current system. From an electronics standpoint, this means running a 12V architecture, and adhering to a 150W maximum power draw.

The prototype is coordinated by an Arduino Nano Every microcontroller. It commands a BTS7960 (IBT-2) dual H-bridge module which drives the 12V bilge blower, and reads two DHT11 temperature and humidity sensors positioned at the duct inlet and outlet. The active thermal elements are two Peltier modules and a resistive heater, all powered from separate bench supplies, giving three independent supplies in total. This separation allowed the current delivered to each element to be adjusted and monitored individually during testing, avoiding voltage or current spikes, and meant the power split between components could be varied without any change to the control wiring.

## Power Architecture

The blower runs from a 12V rail, deliberately matching the existing SOLARSAFE installation in Kenya, which charges a 12V car battery from a 150W solar panel. The fan draws roughly 2A at full duty, so wiring and fusing were sized accordingly. The BTS7960 module isolates its 5V logic side from the motor rail via an on-board 74HC244 buffer, protecting the microcontroller, and all supplies share a common ground referenced at the driver so that motor return current never flows through the Arduino. The resistive heater was run at 24V because the bench supplies were current-limited; raising the voltage allowed the required heating power to be reached within that current limit.

We had some challenges finding power supplies for this project, this tested our teamwork and communication as we were working with many different technicians with differing opinions. James prepared an updated risk assessment for the new power requirement and in case we needed to use a 12V car battery. Josh liaised with the Dyson Centre technicians and I worked with the EIETL to find potential solutions on-site. Ultimately, between the three of us, the power supplies were found and implemented to the satisfaction of the EIETL and Dyson Centre technicians.

## Fan Speed Control

Multi-speed fan operation is achieved by pulse-width modulation through the H-bridge. The RPWM input (Arduino D5) carries the speed signal while LPWM (D6) is held low for single-direction drive, and the R_EN/L_EN enables (D7/D8) act as a software switch that fully disables the bridge when the fan is off. The firmware exposes preset duties of 25%, 50%, 75%, and 100%, which formed the fan-duty axis of the eleven-test experimental matrix. Brushed motors will not reliably start at low duty because of static friction, so for requested duties below 40% the firmware applies a brief full-duty kick-start pulse before settling to the target speed.

## Sensing and Data Logging

The two DHT11 sensors (D2 and D4) report air temperature and relative humidity either side of the dehumidifier module every two seconds. A companion Python script receives this stream and appends it to a timestamped CSV file, producing the datasets analysed in the results report. The DHT11s only resolve to whole units, contributing the ±0.5°C error bars noted in the analysis.

The DHT11s are orientation sensitive as they require flow over the sensor for sensing. By doing some open-loop testing, I found an orientation where both sensors would react quickly to changes and return to the same values at steady-state.

## Reflection and Future Work

The electronics proved reliable across all open and closed-loop tests. The natural next step is to implement volumetric flowrate measurement to give a more informed performance index. The following step is to optimise for full cycle power consumption, potentially with a high-power priming phase followed by a low-power maintenance phase that modulates the heater and Peltier power split to suit ambient conditions. Testing the system in an environmental chamber would significantly improve data validity by emulating the ambient conditions in various parts of sub-Saharan Africa.


<img src="Images/electronics_diagram.png" width="720" alt="Electronics Diagram">