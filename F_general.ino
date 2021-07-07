void PrintVals() {
    Serial.print(("Temperature BMP: "));
    Serial.println(BMPVal);
    Serial.print(("Temperature Senror: "));
    Serial.println(TempVal);
    Serial.print("Door State: ");
    Serial.println(doorState);
    Serial.print("Button State: ");
    Serial.println(buttonState);
}

void UpdateIfChanges(){
  float tempBMP = BMPVal;
  float tempTemp = TempVal;
  UpdateTemperatureValues(false);
   
  if (abs(BMPVal - tempBMP) >= 0.5)
    BMP_value ->save(BMPVal);
      
//  if (abs(TempVal - tempTemp) >= 2)
//    Temperature_value ->save(TempVal);
      
  bool tempDoor = doorState;
  UpdateDoorState();
  if (tempDoor != doorState)
    Door_state ->save(doorState);
  double milkTemp = analogRead(weightSampler)>2000 ? 1 : 0;
  if (milkTemp != milkStatus){
      milkStatus = milkTemp;
      Milk ->save(milkStatus);
  }
}

void UpdateDB(){
  UpdateTemperatureValues(true);
  UpdateDoorState();
  BMP_value ->save(BMPVal);
  Temperature_value ->save(TempVal);
  Door_state ->save(doorState);
  Milk ->save(analogRead(weightSampler) > 2000 ? 1 : 0);
}
