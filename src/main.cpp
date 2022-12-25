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
  Serial.println("Hello World");

    //initialize shared pins
  controllers.init(LATCH_PIN, CLOCK_PIN); 
  //activate first controller ans set the type to SNES
  controllers.setController(0, GameControllers::SNES, DATA_PIN_0);

  bleGamepad.begin();

}

void loop() {
  controllers.poll(); //read all controllers at once
  delay(50);  //read controller just ~20times a second
  if (bleGamepad.isConnected())
    {
        if(controllers.down(0, GameControllers::A))
        {
            bleGamepad.press(BUTTON_1);
        }
        else
        {
            bleGamepad.release(BUTTON_1);
        }

        if(controllers.down(0, GameControllers::B))
        {
            bleGamepad.press(BUTTON_2);
        }
        else
        {
            bleGamepad.release(BUTTON_2);
        }

        if(controllers.down(0, GameControllers::UP))
        {
            bleGamepad.setHat1(DPAD_UP);
        }
        else
        {
            bleGamepad.setHat1(HAT_CENTERED);
        }

    }


  

  

  /*
  if(controllers.down(0, GameControllers::START))  //check if Start was pressed since last loop
    Serial.println("Start was pressed.");
  if(controllers.down(0, GameControllers::SELECT))  //check if Start was pressed since last loop
    Serial.println("Select was pressed.");

  //if(controllers.down(0, GameControllers::A))  //if A button is hold down repeat after 20 loops
    //Serial.println("A");
  //if(controllers.down(0, GameControllers::B))  //if A button is hold down repeat after 20 loops
    //Serial.println("B");
  if(controllers.down(0, GameControllers::X))  //if A button is hold down repeat after 20 loops
    Serial.println("X");
  if(controllers.down(0, GameControllers::Y))  //if A button is hold down repeat after 20 loops
    Serial.println("Y");

  if(controllers.down(0, GameControllers::L))  //if A button is hold down repeat after 20 loops
    Serial.println("L");
    if(controllers.down(0, GameControllers::R))  //if A button is hold down repeat after 20 loops
    Serial.println("R");

  if(controllers.down(0, GameControllers::UP))  //check if B button it's currently pressed down
    Serial.println("UP");
   if(controllers.down(0, GameControllers::DOWN))  //check if B button it's currently pressed down
    Serial.println("DOWN");
   if(controllers.down(0, GameControllers::LEFT))  //check if B button it's currently pressed down
    Serial.println("LEFT");
   if(controllers.down(0, GameControllers::RIGHT))  //check if B button it's currently pressed down
    Serial.println("RIGHT");
  delay(50);  //read controller just ~20times a second
  */
}