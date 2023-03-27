#include <Arduino.h>
#include <HT1621.h>
#include <HX711.h>
#include "config.h"
#include "Bipper.h"

HT1621 displayWeigh;
HT1621 displayPrice; 
HT1621 displayTotalAmount;

HX711 scale;

Bipper bipper(BIPPER_PIN);

long read;
float weight = 0.00 ;
float price = 2.00;


void setup() {
  displayWeigh.begin(2, 3, 4);
  displayPrice.begin(5, 6, 7);
  displayTotalAmount.begin(8, 9, 10);

  Serial.begin(BAUD_SPEED);

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.set_scale(HX711_SCALE);
  scale.tare();
  bipper.beep();
}

void loop() {
  
  if (scale.wait_ready_timeout(1000)) {
    read = scale.get_units(10);
    weight = read / 1000.00;
    displayWeigh.print(weight, PRECICION_DECIMALS);
    displayPrice.print(price, PRECICION_DECIMALS);
    displayTotalAmount.print(weight * price, PRECICION_DECIMALS);
  }
}