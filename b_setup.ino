#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

void setup() {
  Serial.begin(115200);
  
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  WifiConnactionEstablishment();

  change_interval_ms = millis();
  recurent_interval_ms = millis();
  door_interval_ms = millis();
  milk_interval_ms = millis();
  pinMode(buzzer, OUTPUT);
  email_setup();
  milkStatus = analogRead(weightSampler)>0 ? 1 : 0;
}

void WifiConnactionEstablishment(){
  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

    // we are connected
    Serial.println();
    Serial.println(io.statusText());
}
