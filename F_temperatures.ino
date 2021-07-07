double ReadVoltage(byte pin) {
  double reading = analogRead(pin); // Reference voltage is 3v3 so maximum reading is 3v3 = 4095 in range 0 to 4095
  if (reading < 1 || reading > 4095) return 0;
  return -0.000000000000016 * pow(reading, 4) + 0.000000000118171 * pow(reading, 3) - 0.000000301211691 * pow(reading, 2) + 0.001109019271794 * reading + 0.034143524634089;
}

double VoltToCelcius(double v) {
  return 100 * (v - 0.75) +25+12;
}

void UpdateTemperatureValues(bool should_buzz){
  BMPVal = bmp.readTemperature();
  TempVal =  VoltToCelcius(ReadVoltage(temperatueSampler));

    if (should_buzz && (BMPVal > BMPLimit )) {
      Serial.println("GOT HERE AND SOULDN'T");
      String temp = "We have recorded high temperatures. \n BMP: " + String(BMPVal) + "\n Analogic temp: " + String(TempVal);
      SendMessage("High Temperatures recorded", temp);
      buzz();
   }
}
