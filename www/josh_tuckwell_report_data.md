---
title: Results and Data Analysis Report
---

# Results and Data Analysis Report
**Author:** Josh Tuckwell (jdt57)

This report will discuss the design of the experimental test plan and evaluate the performance of the developed dehumidifier prototype. The empirical findings are analysed to determine the optimal component configurations
and assess their practical implications for enhancing Benard’s existing SolarSafe product.

---

## Experimental Test Plan

Following the successful fabrication of the experimental prototype and the integration of dedicated power supplies (see the other 2 reports), empirical testing was initiated. The test matrix was designed to systematically evaluate every 
operational combination of the heating and thermoelectric dehumidifying (Peltier) elements. To assess the impact of airflow rate on system dynamics, each configuration was evaluated across three discrete fan 
duties: 50%, 75%, and 100%. Two additional closed-loop validation tests were appended to evaluate internal recirculation dynamics, establishing the complete 11-test matrix detailed below:

<table>
  <thead>
    <tr>
      <th style="text-align: center;">Test No.</th>
      <th style="text-align: left;">Description</th>
      <th style="text-align: center;">Fan Duty / %</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>1</b></td>
      <td rowspan="3" style="text-align: left; vertical-align: middle;">Peltiers + Heater</td>
      <td style="text-align: center; vertical-align: middle;">50</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>2</b></td>
      <td style="text-align: center; vertical-align: middle;">75</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>3</b></td>
      <td style="text-align: center; vertical-align: middle;">100</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>4</b></td>
      <td rowspan="3" style="text-align: left; vertical-align: middle;">Heater</td>
      <td style="text-align: center; vertical-align: middle;">50</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>5</b></td>
      <td style="text-align: center; vertical-align: middle;">75</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>6</b></td>
      <td style="text-align: center; vertical-align: middle;">100</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>7</b></td>
      <td rowspan="3" style="text-align: left; vertical-align: middle;">Peltiers</td>
      <td style="text-align: center; vertical-align: middle;">50</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>8</b></td>
      <td style="text-align: center; vertical-align: middle;">75</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>9</b></td>
      <td style="text-align: center; vertical-align: middle;">100</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>10</b></td>
      <td style="text-align: left; vertical-align: middle;">Closed Loop with Peltiers</td>
      <td style="text-align: center; vertical-align: middle;">75</td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><b>11</b></td>
      <td style="text-align: left; vertical-align: middle;">Closed Loop with Peltiers and Heater</td>
      <td style="text-align: center; vertical-align: middle;">75</td>
    </tr>
  </tbody>
</table>

---

## Open-Loop Test Results (Tests 1-9)

Ambient baseline conditions remained stable throughout the open-loop testing phase, recorded at an average temperature of 20°C and a relative humidity (RH) of 44%. The initial data set maps the absolute change
in relative humidity ($\Delta\text{RH}$) between the intake sensor (measuring ambient air) and the exhaust sensor at the dehumidifier outlet. 

<img src="Images/temperature_results.png" width="720" alt="Temperature Increase measured in Tests 1-9">

<img src="Images/humidity_results.png" width="720" alt="Humidity decrease measured in Tests 1-9">


While raw humidity reduction provides a useful baseline index, it fails to account for the varying electrical loads demanded by each component configuration. To establish a true measure of efficiency, 
the raw data was normalised against power consumption. By plotting temperature lift ($\Delta T/\text{Watt}$) and moisture extraction ($\Delta\text{RH}/\text{Watt}$), the system's specific energy performance 
can be critically analysed.

<img src="Images/temperature_pwresults.png" width="720" alt="Temperature Increase measured in Tests 1-9 per Watt of Power">

<img src="Images/humidity_pwresults.png" width="720" alt="Humidity decrease measured in Tests 1-9 per Watt of Power">

A notable trend emerged during the 50% fan duty trials, which consistently demonstrated the highest localised performance. This aligns with fundamental thermodynamic principles: 
a lower volumetric flow rate increases the residence time of the air stream across the active elements, allowing a fixed thermal input to heat a smaller mass of air to a higher peak temperature. 
However, to translate these findings effectively to the full-scale SolarSafe system, the total volumetric flow rate must be quantified. Future analyses should evaluate performance metrics in terms of 
$\text{K}\cdot\text{m}^3/(\text{W}\cdot\text{s})$ to account for mass transport. Consequently, the current power-normalised datasets are strictly optimised for comparative evaluation between configurations 
operating at identical fan duties.

Because crop-drying velocity depends heavily on both elevated sensible heat and suppressed relative humidity, these variables are of equal statistical importance to the performance of the SolarSafe unit. 
To synthesize these competing vectors into a singular evaluative tool, a comprehensive performance metric was developed to combine thermal lift and dehumidification capacity.

<img src="Images/Combined_Performance_Graph.png" width="720" alt="Performance Index Results">

Cross-comparing configurations at matching fan duties reveals a distinct operational advantage when deploying the Peltier modules and resistance heaters in tandem. This hybrid configuration out-performed 
individual component operation across two out of three fan duties. Crucially, the combined setup provides balanced optimisation — delivering simultaneous thermal lift and moisture removal rather than prioritising 
one over the other. 

This characteristic introduces vital thermodynamic versatility to the SolarSafe system. While a purely heat-optimised system exhibits diminishing returns in tropical, highly humid environments where ambient temperature 
boundaries are already elevated, this dual-action module maintains robust performance profiles across a wider spectrum of localised climatic conditions.

## Closed-Loop Test Results (Tests 10-11)

Adding temperature comes at a premium and so running the test in a closed loop allows as much of the heat added as possible to remain wihtin the system



