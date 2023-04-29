#include <Arduino.h>
#include <HT1621.h>
#include <HX711.h>
#include "config.h"
#include "Bipper.h"
#include "Keyboard.h"
#include <Wire.h>

HT1621 displayWeigh;
HT1621 displayPrice; 
HT1621 displayTotalAmount;

HX711 scale;
Bipper bipper(BIPPER_PIN);
Keyboard keyboard = Keyboard(ADDRESS_KEYBOARD);

long read;
float weight = 0.00 ;
float price = 4.00;


void keypadEvent(KeypadEvent key){
  switch(keyboard.getState()){
    case PRESSED:
      switch (key){
        case '#':  bipper.beep();  bipper.beep(); break;
        case '*': 
          // do somthing
        break;
        case 'A': price = 3.00; break;
      }
    break;
    case RELEASED:
      switch (key){
        case '*': 
          // do somting else
        break;
      }
    break;
    case HOLD:
      switch (key){
        case '*': // something more 
        break;
      }
    break;
  }
}


void setup() {
  Serial.begin(BAUD_SPEED);

  displayWeigh.begin(2, 3, 4);
  displayPrice.begin(5, 6, 7);
  displayTotalAmount.begin(8, 9, 10);
  
  Wire.begin();
  keyboard.begin();

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.set_scale(HX711_SCALE);
  scale.tare();
  bipper.beep();
}

void loop() {   
    char key = keyboard.getKey();
    if(key){
      Serial.print(key);
      bipper.beep();
    }else {
      read = scale.get_units(3);
      weight = read / 1000.00;
      displayWeigh.print(weight, PRECICION_DECIMALS);
      displayPrice.print(price, PRECICION_DECIMALS);
      displayTotalAmount.print(weight * price, PRECICION_DECIMALS);
    }
    
    
    //if (scale.wait_ready_timeout(100)) {

 // }
  
  
 
}