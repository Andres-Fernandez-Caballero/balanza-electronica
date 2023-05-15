#include <Arduino.h>
#include <HT1621.h>
#include <HX711.h>
#include "config.h"
#include "Bipper.h"
#include "Keyboard.h"
#include <Wire.h>
#include "buttons.h"
#include "globals.h"
#include "History.h"
#include "Display_number.h"


HT1621 displayWeigh;
HT1621 displayPrice; 
HT1621 displayTotalAmount;

DisplayNumber price;

HX711 scale;
Bipper bipper(BIPPER_PIN);
Keyboard keyboard = Keyboard(ADDRESS_KEYBOARD);
History history;

void totalMode() {
  displayTotalAmount.print(history.calculateTotal(), PRECICION_DECIMALS);
  displayWeigh.noDisplay();
  displayPrice.noDisplay();
}

void weightMode() {
  read = scale.get_units(3);
  weight = read / 1000.00;
  displayWeigh.print(weight, PRECICION_DECIMALS);
  displayPrice.print(price.getValue(), PRECICION_DECIMALS);
  displayTotalAmount.print(weight * price.getValue(), PRECICION_DECIMALS);
}

void keypadEvent(KeypadEvent key){
  if(keyboard.getState() == PRESSED) {
      switch (key){
        case CLEAR:
          isWeightMode = true; 
          displayPrice.display();
          displayWeigh.display();
          displayTotalAmount.display();
          price.clear();
          history.clear();  
          Serial.println("new Price: " + String(price.getValue()));
          break;
        case ADD:
          history.add(weight * price.getValue());
          Serial.println("added to history: " + String(price.getValue()));
          bipper.beep();
          price.clear();
          break;
        case GET_TOTAL:
          if(isWeightMode) {
            history.add(price.getValue());
            isWeightMode = false;
            Serial.println("total is " + String(history.calculateTotal()) );;
            bipper.beep();
          }
          break;
        case DOT:
          isDecimalsMode = !isDecimalsMode;
          Serial.println("isDecimalsMode: " + isDecimalsMode? "modo decimal" : "modo entero");
      }
    }else if (keyboard.getState() == RELEASED) {
      switch (key){
        // do logic
      }
    }else if (keyboard.getState() == HOLD) {
      switch (key){
        case DOT: // something more 
        break;
      }
  }
}


void setup() {
  Serial.begin(BAUD_SPEED);
  history = History();
  price = DisplayNumber();

  displayWeigh.begin(
    DISPLAY_WEIGHT_CS, 
    DISPLAY_WEIGHT_WR, 
    DISPLAY_WEIGHT_DATA
  );

  displayPrice.begin(
    DISPLAY_PRICE_CS, 
    DISPLAY_PRICE_WR, 
    DISPLAY_PRICE_DATA
    );

  displayTotalAmount.begin(
    DISPLAY_TOTAL_CS, 
    DISPLAY_TOTAL_WR, 
    DISPLAY_TOTAL_DATA
    );
  
  Wire.begin();
  keyboard.begin();
  keyboard.addEventListener(keypadEvent);

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.set_scale(HX711_SCALE);
  scale.tare();
  bipper.beep();
}

void loop() { 
    char key = keyboard.getKey();
    if(key) {
      if(keyIsNumber(key)){
        float keyNumberValue = key - '0';
        if(isDecimalsMode){
          price.addDecimal(keyNumberValue);
        }else {
          price.addDigit(keyNumberValue);
        }
          Serial.println("new Price: " + String(price.getValue()));
      }
      bipper.beep();
    }else {
      if(isWeightMode) {
        weightMode();     
      }else {
        totalMode();
      }
    } 
}