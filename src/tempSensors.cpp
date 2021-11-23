// #include <Arduino.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>

// extern float tempC, newTemp, oldTemp;

// void tempRead()
// {
//   if (millis() - timer >= del)
//   {
//     timer = millis();

//     sensors.requestTemperatures();
//     tempC = sensors.getTempC(sensor);
//     newTemp = tempC;

//     Serial.print("tempC");
//     Serial.print("-");
//     Serial.print(tempC);
//     Serial.print(" ");
//     Serial.print("newTemp");
//     Serial.print("-");
//     Serial.print(newTemp);
//     Serial.print(" ");
//     Serial.print("oldTemp");
//     Serial.print("-");
//     Serial.println(oldTemp);
//   }
// }