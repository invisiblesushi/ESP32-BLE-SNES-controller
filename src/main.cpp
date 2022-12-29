#include <Arduino.h>
#include <GameControllers.h>
#include <BleGamepad.h> // https://github.com/lemmingDev/ESP32-BLE-Gamepad

//shared pins between all controllers
const int LATCH_PIN = 2;
const int CLOCK_PIN = 4;
//individual data pin for each controller
const int DATA_PIN_0 = 15; 

GameControllers controllers;
BleGamepad bleGamepad;
int previousButton1State = HIGH;

void setup() {
  Serial.begin(115200);

  //initialize shared pins
  controllers.init(LATCH_PIN, CLOCK_PIN); 
  //activate first controller ans set the type to SNES
  controllers.setController(0, GameControllers::SNES, DATA_PIN_0);

  bleGamepad.begin();
}



void loop() {
  controllers.poll(); //read all controllers at once

  if (bleGamepad.isConnected())
    {
      // A/B/X/Y
      if (controllers.down(0, GameControllers::A)){
        bleGamepad.press(BUTTON_1);
      }
      else{
          bleGamepad.release(BUTTON_1);
      }

      if(controllers.down(0, GameControllers::B)){
          bleGamepad.press(BUTTON_2);
      }
      else{
          bleGamepad.release(BUTTON_2);
      }

      if(controllers.down(0, GameControllers::X)){
          bleGamepad.press(BUTTON_4);
      }
      else{
          bleGamepad.release(BUTTON_4);
      }

      if(controllers.down(0, GameControllers::Y)){
          bleGamepad.press(BUTTON_5);
      }
      else{
          bleGamepad.release(BUTTON_5);
      }

      // L1/R1
      if(controllers.down(0, GameControllers::L)){
          bleGamepad.press(BUTTON_7);
      }
      else{
          bleGamepad.release(BUTTON_7);
      }
      if(controllers.down(0, GameControllers::R)){
          bleGamepad.press(BUTTON_8);
      }
      else{
          bleGamepad.release(BUTTON_8);
      }

      // Start/Select
      if(controllers.down(0, GameControllers::START)){
          bleGamepad.press(BUTTON_12);
      }
      else{
          bleGamepad.release(BUTTON_12);
      }
      if(controllers.down(0, GameControllers::SELECT)){
          bleGamepad.press(BUTTON_11);
      }
      else{
          bleGamepad.release(BUTTON_11);
      }

      // DPAD
      if(controllers.down(0, GameControllers::UP)){
        bleGamepad.setHat1(DPAD_UP);
      }
      else if (controllers.down(0, GameControllers::DOWN)){        
        bleGamepad.setHat1(DPAD_DOWN);
      }
      else if (controllers.down(0, GameControllers::LEFT)){
        bleGamepad.setHat1(DPAD_LEFT);
      }      
      else if (controllers.down(0, GameControllers::RIGHT)){
        bleGamepad.setHat1(DPAD_RIGHT);
      }
      else{
        bleGamepad.setHat1(DPAD_CENTERED);
      }


    }
}