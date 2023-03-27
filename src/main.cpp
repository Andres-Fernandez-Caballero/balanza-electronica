#include <Arduino.h>
#include <HT1621.h>
#include "config.h"

HT1621 displayWeigh;
HT1621 displayPrice; 
HT1621 displayTotalAmount;

double weight = 1.50;
double price = 2.00;


void setup() {
  displayWeigh.begin(2, 3, 4);
  displayPrice.begin(5, 6, 7);
  displayTotalAmount.begin(8, 9, 10);
}

void loop() {
  displayWeigh.print(weight, PRECICION_DECIMALS);
  displayPrice.print(price, PRECICION_DECIMALS);
  displayTotalAmount.print(weight * price, PRECICION_DECIMALS);
}