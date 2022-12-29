# ESP32-BLE-SNES-controller

Project for converting SNES controller to a bluetooth gamepad using the ESP32 microcontroller.

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
