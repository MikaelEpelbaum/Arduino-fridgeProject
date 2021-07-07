void UpdateDoorState(){
  if (analogRead(photoSampler)- photoVal > 500){
    doorState = true;
    door_interval_ms = millis();
    doorEmailSent = false;
  }
  else if (photoVal - analogRead(photoSampler) > 500){
    doorState = false;
    float length = float(millis()-door_interval_ms)/1000;
    Door_time ->save(length);
  }
  if ((millis()-door_interval_ms)/1000 > DoorLimit && doorState){
    doorMessage();
    }
  photoVal = analogRead(photoSampler);
}
