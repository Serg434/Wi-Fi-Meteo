#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include "DHT.h"
#include <EncButton.h>

#include <rus.h>
#include <sounds.h>

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
#define baclightPin 21
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define displayColor ST7735_BLACK
#define textColor ST7735_MAGENTA

// bool btnFlag = false;
#define tempPin 13
#define dhtPin 32
#define DHTTYPE DHT22
DHT dht(dhtPin, DHTTYPE);

// char sensorPrintout[4];
#define startBtn 26
int backlight = 0;
volatile bool startFlag = true;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
unsigned long timeFade;
unsigned long delFade = 10;

#define countBtn 27
volatile unsigned long countBtnTimer;
volatile unsigned long delCountBtn = 300;

volatile int count = 0;
int newCount = 0;

// #define buzBtn 27
// int buzPin = 33;
// volatile int btnClk = 0;
// volatile int songNum = 0;

unsigned long timerDS;
unsigned long timerDHT;
unsigned long delDS = 2000;
unsigned long delDHT = 3000;

float tempC, humDHT, tempDHT, newTempDS, oldTempDS, oldTempDHT, newTempDHT, newHumDHT;

const int busPin = tempPin;
OneWire bus(busPin);
DallasTemperature sensors(&bus);
DeviceAddress sensor;

// String utf8rus(String source);
void tempReadDS();
void tempReadDHT();
void updateTempDS();
void updateTempDHT();
void displayInit();
// void goToSleep();
// void setFlag();
// void wakeUp();
// void startBtnClick();
void playMusic();
void stopMusic();
void countFunc();
void fadeFunc();
void fadeFuncFlag();
void countUpdate();

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  sensors.begin();
  if (!sensors.getAddress(sensor, 0))
  {
    Serial.println("NO DS18B20 FOUND!");
  }

  dht.begin();
  // pinMode(buzPin, OUTPUT);
  pinMode(countBtn, INPUT_PULLUP);
  pinMode(startBtn, INPUT_PULLUP);
  pinMode(baclightPin, OUTPUT);
  // digitalWrite(baclightPin, HIGH);
  attachInterrupt(countBtn, countFunc, FALLING);
  attachInterrupt(startBtn, fadeFuncFlag, FALLING);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(baclightPin, ledChannel);

  displayInit();

  // test();
  // piratesSong();
}

void loop()
{

  tempReadDS();
  updateTempDS();
  tempReadDHT();
  updateTempDHT();
  countUpdate();
  fadeFunc();
  // playMusic();
}

void displayInit()
{
  tft.cp437(true);
  pinMode(baclightPin, OUTPUT);
  digitalWrite(baclightPin, HIGH);
  tft.initR(INITR_GREENTAB);
  tft.setRotation(2);
  tft.setTextWrap(false);
  tft.fillScreen(displayColor); //Очистить дисплей
  tft.setCursor(0, 0);          //Поставить курсор Х У
  tft.setTextColor(textColor);  //Цвет шрифта
  tft.setTextSize(1);           //Размер шрифта
  tft.println(utf8rus("Температура DS18B20:"));
  tft.setTextSize(2);
  tft.setCursor(50, 20);
  tft.print("\xB0"
            "C");

  tft.setCursor(0, 40);        //Поставить курсор Х У
  tft.setTextColor(textColor); //Цвет шрифта
  tft.setTextSize(1);          //Размер шрифта
  tft.println(utf8rus("Температура DHT22:"));
  tft.setTextSize(2);
  tft.setCursor(50, 60);
  tft.print("\xB0"
            "C");

  tft.setCursor(0, 80);        //Поставить курсор Х У
  tft.setTextColor(textColor); //Цвет шрифта
  tft.setTextSize(1);          //Размер шрифта
  tft.println(utf8rus("Влажность DHT22:"));
  tft.setTextSize(2);
  tft.setCursor(50, 100);
  tft.print("%");

  tft.setCursor(0, 140);       //Поставить курсор Х У
  tft.setTextColor(textColor); //Цвет шрифта
  tft.setTextSize(2);          //Размер шрифта
  tft.println(utf8rus("Счетчик:"));
  tft.setCursor(92, 140);
  tft.println(count);
}

void tempReadDS()
{
  if (millis() - timerDS >= delDS)
  {
    timerDS = millis();

    sensors.requestTemperatures();
    tempC = sensors.getTempC(sensor);
    newTempDS = tempC;

    // Serial.print("tempC");
    // Serial.print("-");
    // Serial.print(tempC);
    // Serial.print(" ");
    // Serial.print("newTemp");
    // Serial.print("-");
    // Serial.print(newTempDS);
    // Serial.print(" ");
    // Serial.print("oldTemp");
    // Serial.print("-");
    // Serial.println(oldTempDS);
  }
}

void tempReadDHT()
{
  if (millis() - timerDHT >= delDHT)
  {
    timerDHT = millis();

    humDHT = dht.readHumidity();
    tempDHT = dht.readTemperature();
    newTempDHT = tempDHT;
    newHumDHT = humDHT;
  }
}

void updateTempDS()
{
  if (newTempDS != oldTempDS)
  {
    tft.setTextColor(textColor, displayColor);
    tft.setTextSize(2);
    tft.setCursor(0, 20);
    tft.print(tempC, 1);
    oldTempDS = newTempDS;
    Serial.println("New data DS");
  }
}

void updateTempDHT()
{
  if (newTempDHT != oldTempDHT)
  {
    tft.setTextColor(textColor, displayColor);
    tft.setTextSize(2);
    tft.setCursor(0, 60);
    tft.print(tempDHT, 1);
    tft.setCursor(0, 100);
    tft.print(humDHT, 1);
    oldTempDHT = newTempDHT;
    Serial.println("New data DHT");
    // Serial.print("Old Temp DHT = ");
    // Serial.print(oldTempDHT);
    // Serial.print("New temp DHT = ");
    // Serial.print(newTempDHT);
  }
}
// void playMusic()
// {
//   // int buttonState = digitalRead(buzBtn); // read new state
//   // volatile int songNum = 0;
//   int songCount = 2;
//   if(songNum = 0){
//     digitalWrite(buzPin,LOW);
//   }
//     else if(songNum == 1){
// piratesSong();
//   }
//   else if(songNum == 2){
//     marioMario();
//   }
//   if(songNum > songCount) {
//     songNum = 0;
//   }
// }

// void stopMusic(){
//   digitalWrite(buzPin, LOW);
//   Serial.println("Stop Music");
// }

void countFunc()
{
  detachInterrupt(countBtn);
  if (millis() - countBtnTimer >= delCountBtn)
  {
    countBtnTimer = millis();
    count++;
    Serial.println(count);
  }
  attachInterrupt(countBtn, countFunc, FALLING);
}

void fadeFunc()
{
  if (startFlag == true)
    for (; backlight <= 255 && millis() - timeFade >= delFade; backlight++)
    {
      timeFade = millis();
      // меняем яркость светодиода
      ledcWrite(ledChannel, backlight);
    }
  else
  {
    for (; backlight >= 0 && millis() - timeFade >= delFade; backlight--)
    {
      timeFade = millis();
      // меняем яркость светодиода при помощи ШИМ:
      ledcWrite(ledChannel, backlight);
    }
    count = 0;
    tft.setTextColor(textColor, displayColor); //Цвет шрифта сиреневый
    tft.setCursor(92, 140);
    tft.println("0   ");
  }
}

void fadeFuncFlag()
{
  detachInterrupt(startBtn);
  if (millis() - countBtnTimer >= (delCountBtn * 2))
  {
    countBtnTimer = millis();
    startFlag = !startFlag;
    Serial.print("StartFlag = ");
    Serial.println(startFlag);
  }
  attachInterrupt(startBtn, fadeFuncFlag, FALLING);
}

void countUpdate()
{
  if (newCount != count)
  {
    // tft.setCursor(0, 140);                     //Поставить курсор Х У
    tft.setTextColor(textColor, displayColor); //Цвет шрифта сиреневый
    tft.setCursor(92, 140);
    tft.println(count);
    // Serial.println(count);
    newCount = count;
  }
}