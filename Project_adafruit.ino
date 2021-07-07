#include "a_Wifi.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#include "a_Variables.h"
#include "a_Functions.h"

void loop() {
  io.run();
    
  if((int)(millis() - change_interval_ms) >= 2000){
    change_interval_ms = millis();
    UpdateIfChanges();
  }
  if((int)(millis() - milk_interval_ms) >=  5 * 60 * 1000){
    milk_interval_ms = millis();
    noMilk();
  }
  
  if((int)(millis() - recurent_interval_ms) >= 5* 60 * 1000){
    recurent_interval_ms = millis();
    UpdateDB();
  }  
}
