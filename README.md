# ESP32-BLE-SNES-controller

Project for converting SNES controller to a bluetooth gamepad using the ESP32 microcontroller.

<img src="/Image/PCB.png" width="500" />
<img src="/Image/Schematic.png" width="500" />

# GPIO conncetion
|       ESP32 pin | SNES Controller | Wire color |
|---:|:-------:|:--------:|
| 2  |   Latch |   Yellow | 
| 4  |   Clock |   Blue   | 
| 15 |   Data  |   Red    | 
|    |   GND   |   Black  | 
|    | VCC 3.3v|   White  | 

# Libaries
ESP32-BLE-Gamepad - https://github.com/lemmingDev/ESP32-BLE-Gamepad
ArduinoGameController - https://github.com/bitluni/ArduinoGameController

# Parts list
- ESP32-S
- 18650 1A Lipo Battery Charging Board Charger Module TP4056 Type-C
- 300mAh 601235 Rechargeable Lithium Polymer Battery
- LM1117MP-3.3/TR 3.3v Voltage Regulator
- 47 µF capasitor D6.3xL11mm
- Switch SK12D07VG3
- Tactile Tact push button 3x6x2.5MM G73
- 10k resistor
- 2.54mm pin header

[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Finvisiblesushi%2FESP32-BLE-SNES-controller&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)
