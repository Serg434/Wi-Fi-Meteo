#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
#define BACKLIGHT 7
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#define displayColor 0x780F
#define textColor ST7735_MAGENTA

// #define startBtn 2

// bool btnFlag = false;
#define tempPin 13
// char sensorPrintout[4];

// #define buzPin 12

unsigned long timer;
unsigned long del = 2000;

float tempC, newTemp, oldTemp;

const int busPin = tempPin;
OneWire bus(busPin);
DallasTemperature sensors(&bus);
DeviceAddress sensor;

String utf8rus(String source);
void tempRead();
void updateDisplay();
void displayInit();
// void goToSleep();
// void setFlag();
// void wakeUp();
// void startBtnClick();

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  sensors.begin();
  if (!sensors.getAddress(sensor, 0))
  {
    Serial.println("NO DS18B20 FOUND!");
  }
//   pinMode(BACKLIGHT, OUTPUT);
//   digitalWrite(BACKLIGHT, HIGH);

//   pinMode(startBtn, INPUT_PULLUP);


  tft.cp437(true);

  displayInit();

}

void loop()
{
  // put your main code here, to run repeatedly:

//   // startBtnClick();

  tempRead();
  updateDisplay();
}

void displayInit()
{
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);
  tft.initR(INITR_GREENTAB);
  tft.setRotation(2);
  tft.setTextWrap(false);
  tft.fillScreen(0x780F);      //Очистить дисплей
  tft.setCursor(0, 0);         //Поставить курсор Х У
  tft.setTextColor(textColor); //Цвет шрифта сиреневый
  tft.setTextSize(1);          //Размер шрифта "1"
  tft.println(utf8rus("Температура:"));
  tft.setTextSize(2);
  tft.setCursor(50, 20);
  tft.print("\xB0" "C");
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
    //  Serial.println(tempC);
    tft.setTextColor(textColor, displayColor);
    tft.setCursor(0, 20);
    tft.print(tempC, 1);
    oldTemp = newTemp;
    Serial.println("New data");
  }
}

// // void startBtnClick()
// // {
// //   bool btnState = !digitalRead(2);
// //   if (btnState && !flag)
// //   { // обработчик нажатия
// //     flag = true;
// //     Serial.println("press");
// //   }
// //   if (!btnState && flag)
// //   { // обработчик отпускания
// //     flag = false;
// //     Serial.println("release");
// //   }
// // }

String utf8rus(String source)
{
  int i, k;
  String target;
  unsigned char n;
  char m[2] = {'0', '\0'};

  k = source.length();
  i = 0;

  while (i < k)
  {
    n = source[i];
    i++;

    if (n >= 0xC0)
    {
      switch (n)
      {
      case 0xD0:
      {
        n = source[i];
        i++;
        if (n == 0x81)
        {
          n = 0xA8;
          break;
        }
        if (n >= 0x90 && n <= 0xBF)
          n = n + 0x30;
        break;
      }
      case 0xD1:
      {
        n = source[i];
        i++;
        if (n == 0x91)
        {
          n = 0xB8;
          break;
        }
        if (n >= 0x80 && n <= 0x8F)
          n = n + 0x70;
        break;
      }
      }
    }
    m[0] = n;
    target = target + String(m);
  }
  return target;
}
