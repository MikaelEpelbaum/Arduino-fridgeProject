const String Subject = "Refrigirator door open exessively";
String content = "We have noticed that your refrigirator door was open for: ";
String doorContent = content + String(int(DoorLimit)/60) + ":" + String(int(DoorLimit)%60) + " minutes.";

const String milkSubject = "Milk Allert";
String milkContent = "We think you have finnished your milk and should think of replacing it";

void doorMessage() {
      if (!doorEmailSent){
        buzz();
        SendMessage(Subject, doorContent);
        doorEmailSent = true;
      }
}

void noMilk() {
    milkStatus = analogRead(weightSampler)>2000 ? 1 : 0;
    if (!milkStatus && !milkEmailSent){
      SendMessage(milkSubject, milkContent);
      milkEmailSent = true;
    }
    if (milkStatus && milkEmailSent)
      milkEmailSent = false;
}

void buzz() {
  digitalWrite(buzzer, HIGH);
  buttonState =  ReadVoltage(buttonSampler) > 3 ? 1:0;
  buzzing_ms = millis();
  while ((int)(millis()- buzzing_ms) < 3000 && !buttonState){
    buttonState =  ReadVoltage(buttonSampler) > 3 ? 1:0;
  }
  buttonState = false;
  digitalWrite(buzzer, LOW);
  }
  
