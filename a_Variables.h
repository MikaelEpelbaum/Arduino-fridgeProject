// adafruit recorded values
AdafruitIO_Feed *Door_state = io.feed("door");
AdafruitIO_Feed *Door_time = io.feed("doorTime");
AdafruitIO_Feed *Temperature_value = io.feed("temp");
AdafruitIO_Feed *BMP_value = io.feed("bmp");
AdafruitIO_Feed *Milk = io.feed("milk");


Adafruit_BMP280 bmp;
const int temperatueSampler = 32;
const int buttonSampler = 39;
const int photoSampler = 34;
const int buzzer = 33;
const int weightSampler = 36;


const int TempLimit = 37;
const int BMPLimit = 10;
const int DoorLimit = 30; //seconds


//Variables
bool buttonState;
bool doorState;
float photoVal = 0;
float BMPVal;
float TempVal;
float milkStatus;

//Notif variables
bool doorEmailSent = false;
bool TempEmailSent = false;
bool milkEmailSent = false;


static uint64_t change_interval_ms;
static uint64_t recurent_interval_ms;
static uint64_t print_interval_ms;
static uint64_t door_interval_ms;
static uint64_t buzzing_ms;
static uint64_t milk_interval_ms;
