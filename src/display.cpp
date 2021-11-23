// #include <Arduino.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_ST7735.h>
// #include <Adafruit_I2CDevice.h>
// #include <SPI.h>

// #include <rus.h>

// #define TFT_CS 5
// #define TFT_DC 2
// #define TFT_RST 4
// #define BACKLIGHT 7
// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// #define displayColor 0x780F
// #define textColor ST7735_MAGENTA

// void displayInit()
// {
//     tft.cp437(true);
//     pinMode(BACKLIGHT, OUTPUT);
//     digitalWrite(BACKLIGHT, HIGH);
//     tft.initR(INITR_GREENTAB);
//     tft.setRotation(2);
//     tft.setTextWrap(false);
//     tft.fillScreen(0x780F);      //Очистить дисплей
//     tft.setCursor(0, 0);         //Поставить курсор Х У
//     tft.setTextColor(textColor); //Цвет шрифта сиреневый
//     tft.setTextSize(1);          //Размер шрифта "1"
//     tft.println(utf8rus("Температура:"));
//     tft.setTextSize(2);
//     tft.setCursor(50, 20);
//     tft.print("\xB0"
//               "C");
// }
// void updateDisplay()
// {
//     if (newTemp != oldTemp)
//     {
//         //  Serial.println(tempC);
//         tft.setTextColor(textColor, displayColor);
//         tft.setCursor(0, 20);
//         tft.print(tempC, 1);
//         oldTemp = newTemp;
//         Serial.println("New data");
//     }
// }