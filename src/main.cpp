#include <Arduino.h>
#include <HT1621.h>
#include <HX711.h>
#include "config.h"
#include "Bipper.h"
#include "Keyboard.h"
#include <Wire.h>
#include "buttons.h"

HT1621 displayWeigh;
HT1621 displayPrice; 
HT1621 displayTotalAmount;

HX711 scale;
Bipper bipper(BIPPER_PIN);
Keyboard keyboard = Keyboard(ADDRESS_KEYBOARD);

long read;
float weight = 0.00 ;
float price = 0.00;
float priceDecimals = 0;
int priceDecimalsCounter = 1;

bool isDecimalsMode = false;

void keypadEvent(KeypadEvent key){
  if(keyboard.getState() == PRESSED) {
      switch (key){
        case CLEAR: 
          price *= 0; 
          priceDecimals = 0;
          priceDecimalsCounter = 1;
          
          Serial.println("new Price: " + String(price));
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

  displayWeigh.begin(2, 3, 4);
  displayPrice.begin(5, 6, 7);
  displayTotalAmount.begin(8, 9, 10);
  
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
    if(key){
      if(keyIsNumber(key)){
        if(isDecimalsMode){
          priceDecimals = float(key - '0') / (priceDecimalsCounter *= 10);
          Serial.println("decimals " + String(priceDecimals));
          price = price + priceDecimals;
        }else {
          price = price * 10 + (key - '0');
        }
          Serial.println("new Price: " + String(price));
      }

      bipper.beep();
    }else {
      read = scale.get_units(3);
      weight = read / 1000.00;
      displayWeigh.print(weight, PRECICION_DECIMALS);
      displayPrice.print(price, PRECICION_DECIMALS);
      displayTotalAmount.print(weight * price, PRECICION_DECIMALS);
    } 
}