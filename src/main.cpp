#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

#include <rus.h>
#include <sounds.h>

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
#define BACKLIGHT 7
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define displayColor ST7735_WHITE
#define textColor ST7735_MAGENTA

// bool btnFlag = false;
#define tempPin 13
// char sensorPrintout[4];
#define startBtn 26

#define buzBtn 27
int buzPin = 33;
volatile int btnClk = 0;
volatile int songNum = 0;

unsigned long timer;
unsigned long del = 2000;

float tempC, newTemp, oldTemp;

const int busPin = tempPin;
OneWire bus(busPin);
DallasTemperature sensors(&bus);
DeviceAddress sensor;

// String utf8rus(String source);
void tempRead();
void updateDisplay();
void displayInit();
// void goToSleep();
// void setFlag();
// void wakeUp();
// void startBtnClick();
void playMusic();
void stopMusic();
void count();
void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  sensors.begin();
  if (!sensors.getAddress(sensor, 0))
  {
    Serial.println("NO DS18B20 FOUND!");
  }

  pinMode(buzPin, OUTPUT);
  pinMode(buzBtn, INPUT_PULLUP);
  pinMode(startBtn, INPUT_PULLUP);

  attachInterrupt(buzBtn, count, FALLING);

  //   pinMode(BACKLIGHT, OUTPUT);
  //   digitalWrite(BACKLIGHT, HIGH);

  //   pinMode(startBtn, INPUT_PULLUP);

  displayInit();
  // test();
  // piratesSong();
}

void loop()
{
//   if(digitalRead(startBtn == HIGH)){
//     Serial.println("startBtn Pressed");
//     // piratesSong();
//   }
//     else{
//       digitalWrite(buzPin, LOW);
//     }
  
  // if (buttonState == LOW) {
  // Serial.println("The button is being pressed");
  //   piratesSong(); // turn on
  // }
  // else
  // if (buttonState == HIGH) {
  //   // Serial.println("The button is unpressed");
  //   digitalWrite(buzPin, LOW);  // turn off
  // }

  //   // startBtnClick();

  tempRead();
  updateDisplay();
  playMusic();
}

void displayInit()
{
  tft.cp437(true);
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);
  tft.initR(INITR_GREENTAB);
  tft.setRotation(2);
  tft.setTextWrap(false);
  tft.fillScreen(displayColor); //Очистить дисплей
  tft.setCursor(0, 0);          //Поставить курсор Х У
  tft.setTextColor(textColor);  //Цвет шрифта сиреневый
  tft.setTextSize(1);           //Размер шрифта "1"
  tft.println(utf8rus("Температура:"));
  tft.setTextSize(2);
  tft.setCursor(50, 20);
  tft.print("\xB0"
            "C");
}

void tempRead()
{
  if (millis() - timer >= del)
  {
    timer = millis();

    sensors.requestTemperatures();
    tempC = sensors.getTempC(sensor);
    newTemp = tempC;

    Serial.print("tempC");
    Serial.print("-");
    Serial.print(tempC);
    Serial.print(" ");
    Serial.print("newTemp");
    Serial.print("-");
    Serial.print(newTemp);
    Serial.print(" ");
    Serial.print("oldTemp");
    Serial.print("-");
    Serial.println(oldTemp);

  }
}

void updateDisplay()
{
  if (newTemp != oldTemp)
  {
    tft.setTextColor(textColor, displayColor);
    tft.setCursor(0, 20);
    tft.print(tempC, 1);
    oldTemp = newTemp;
    Serial.println("New data");
  }
}

void playMusic()
{
  // int buttonState = digitalRead(buzBtn); // read new state
  // volatile int songNum = 0;
  int songCount = 2;
  if(songNum = 0){
    digitalWrite(buzPin,LOW);
  }
    else if(songNum = 1){
piratesSong();
  }
  else if(songNum = 2){
    marioMario();
  }
  if(songNum > songCount) {
    songNum = 0;
  }
}

void stopMusic(){
  digitalWrite(buzPin, LOW);
  Serial.println("Stop Music");
}

void count(){
  songNum++;
  Serial.println(songNum);
}