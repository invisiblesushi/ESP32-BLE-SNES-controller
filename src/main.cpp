#include <Arduino.h>
#include <GameControllers.h>
#include <BleGamepad.h> // https://github.com/lemmingDev/ESP32-BLE-Gamepad

const int LATCH_PIN = 2;
const int CLOCK_PIN = 4;
const int DATA_PIN_0 = 15; 

GameControllers controllers;
BleGamepad bleGamepad("ESP32 SNES Gamepad", "Espressif", 100);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE gamepad");

  controllers.init(LATCH_PIN, CLOCK_PIN); 
  controllers.setController(0, GameControllers::SNES, DATA_PIN_0);

  bleGamepad.begin();
}

void handleButtonPress(int controllerIndex, GameControllers::Button button, int bleButton) {
  if (controllers.down(controllerIndex, button)) {
    bleGamepad.press(bleButton);
  } else {
    bleGamepad.release(bleButton);
  }
}

void handleDPadPress() {
  if (controllers.down(0, GameControllers::UP)) {
    bleGamepad.setHat1(DPAD_UP);
  } else if (controllers.down(0, GameControllers::DOWN)) {
    bleGamepad.setHat1(DPAD_DOWN);
  } else if (controllers.down(0, GameControllers::LEFT)) {
    bleGamepad.setHat1(DPAD_LEFT);
  } else if (controllers.down(0, GameControllers::RIGHT)) {
    bleGamepad.setHat1(DPAD_RIGHT);
  } else {
    bleGamepad.setHat1(DPAD_CENTERED);
  }
}

void loop() {
  controllers.poll(); //read all controllers at once

  if (!bleGamepad.isConnected())
    {
      return;
    }

  // A/B/X/Y buttons
  handleButtonPress(0, GameControllers::A, BUTTON_1);
  handleButtonPress(0, GameControllers::B, BUTTON_2);
  handleButtonPress(0, GameControllers::X, BUTTON_4);
  handleButtonPress(0, GameControllers::Y, BUTTON_5);

  // L1/R1 buttons
  handleButtonPress(0, GameControllers::L, BUTTON_7);
  handleButtonPress(0, GameControllers::R, BUTTON_8);

  // Start/Select buttons
  handleButtonPress(0, GameControllers::START, BUTTON_12);
  handleButtonPress(0, GameControllers::SELECT, BUTTON_11);

  // DPAD
  handleDPadPress();
}

