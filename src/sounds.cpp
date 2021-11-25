#include <Arduino.h>
#include <Tone32.h>

extern int buzPin;

#define BUZZER_CHANNEL 0

void test()
{
  tone(buzPin, NOTE_C4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
  tone(buzPin, NOTE_D4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
  tone(buzPin, NOTE_E4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
  tone(buzPin, NOTE_F4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
  tone(buzPin, NOTE_G4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
  tone(buzPin, NOTE_A4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
  tone(buzPin, NOTE_B4, 500, BUZZER_CHANNEL);
  noTone(buzPin, BUZZER_CHANNEL);
}

void starWars()
{
  int notes[] = {
  392, 392, 392, 311, 466, 392, 311, 466, 392,
  587, 587, 587, 622, 466, 369, 311, 466, 392,
  784, 392, 392, 784, 739, 698, 659, 622, 659,
  415, 554, 523, 493, 466, 440, 466,
  311, 369, 311, 466, 392
};
int times[] = {
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 250, 100, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 750
};

 for (int i = 0; i < 39; i++){
  tone(buzPin, notes[i], times[i]/3,BUZZER_CHANNEL);
  delay(times[i]*2);
  noTone(buzPin,BUZZER_CHANNEL);
 }

}

void piratesSong()
{

  const float songSpeed = 1.25;

  // Music notes of the song, 0 is a rest/pulse
  int notes[] = {
      NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
      NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
      NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
      NOTE_A4, NOTE_G4, NOTE_A4, 0,

      NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
      NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
      NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
      NOTE_A4, NOTE_G4, NOTE_A4, 0,

      NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
      NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
      NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
      NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

      NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
      NOTE_D5, NOTE_E5, NOTE_A4, 0,
      NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
      NOTE_C5, NOTE_A4, NOTE_B4, 0,

      NOTE_A4, NOTE_A4,
      //Repeat of first part
      NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
      NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
      NOTE_A4, NOTE_G4, NOTE_A4, 0,

      NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
      NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
      NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
      NOTE_A4, NOTE_G4, NOTE_A4, 0,

      NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
      NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
      NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
      NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

      NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
      NOTE_D5, NOTE_E5, NOTE_A4, 0,
      NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
      NOTE_C5, NOTE_A4, NOTE_B4, 0,
      //End of Repeat

      NOTE_E5, 0, 0, NOTE_F5, 0, 0,
      NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
      NOTE_D5, 0, 0, NOTE_C5, 0, 0,
      NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

      NOTE_E5, 0, 0, NOTE_F5, 0, 0,
      NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
      NOTE_D5, 0, 0, NOTE_C5, 0, 0,
      NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4};

  // Durations (in ms) of each music note of the song
  // Quarter Note is 250 ms when songSpeed = 1.0
  int durations[] = {
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 375, 125,

      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 375, 125,

      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 125, 250, 125,

      125, 125, 250, 125, 125,
      250, 125, 250, 125,
      125, 125, 250, 125, 125,
      125, 125, 375, 375,

      250, 125,
      //Rpeat of First Part
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 375, 125,

      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 375, 125,

      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 250, 125, 125,
      125, 125, 125, 250, 125,

      125, 125, 250, 125, 125,
      250, 125, 250, 125,
      125, 125, 250, 125, 125,
      125, 125, 375, 375,
      //End of Repeat

      250, 125, 375, 250, 125, 375,
      125, 125, 125, 125, 125, 125, 125, 125, 375,
      250, 125, 375, 250, 125, 375,
      125, 125, 125, 125, 125, 500,

      250, 125, 375, 250, 125, 375,
      125, 125, 125, 125, 125, 125, 125, 125, 375,
      250, 125, 375, 250, 125, 375,
      125, 125, 125, 125, 125, 500};

  const int totalNotes = sizeof(notes) / sizeof(int);
  // Loop through each note
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      tone(buzPin, notes[i], wait, BUZZER_CHANNEL); // tone(pin, frequency, duration)
    }
    else
    {
      noTone(buzPin, BUZZER_CHANNEL);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }
}



void pineSong(){

  const float songSpeed = 5;

  int notes[] = {
  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_A4, NOTE_F4, NOTE_C4, NOTE_C4,
  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_AS4,
  NOTE_G4, NOTE_C5, 0, NOTE_C5, NOTE_D4,
  NOTE_D4, NOTE_AS4,NOTE_AS4,NOTE_A4,
  NOTE_G4, NOTE_F4, NOTE_C4, NOTE_A4,
  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4
};

int times[] = {
  400,400,400,400,
  400,400,400,400,
  400,400,400,400,
  400,600,20,400,400,
  400,400,400,400,
  400,400,400,400,
  400,400,400,600
};
 for (int i = 0; i < 29; i++){
  tone(buzPin, notes[i],times[i]/songSpeed,BUZZER_CHANNEL);
  delay(times[i]);
  noTone(buzPin,BUZZER_CHANNEL);
 }
}


void superMario(){
  //##############**"Mario underworld" **##############//
int MarioUW_note[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,NOTE_AS3, NOTE_AS4, 0, 0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0,0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,NOTE_DS3, NOTE_DS4, 0, 0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,  NOTE_AS3, NOTE_A3, NOTE_GS3,0, 0, 0
};
int MarioUW_duration[] = {
 12, 12, 12, 12,12, 12, 6,3,
 12, 12, 12, 12, 12, 12, 6, 3,
 12, 12, 12, 12, 12, 12, 6,
 3, 12, 12, 12, 12,
 12, 12, 6, 6, 18, 18, 18,
 6, 6, 6, 6,6, 6,
 18, 18, 18, 18, 18, 18, 10, 10, 10,
 10, 10, 10, 3, 3, 3
};
//###########End of Mario underworld#############//
  
    for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
    tone(buzPin, MarioUW_note[thisNote], noteDuration,BUZZER_CHANNEL);
    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(buzPin,BUZZER_CHANNEL); //stop music on pin 8 
    }
}

void Play_Titanic()
{
  //##############**"Titanic" **##############//
int Titanic_note[] = {
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4,
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_F5,
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4,
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_B3, NOTE_E4,
NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4


};
int Titanic_duration[] = {
8,8,8,8,8,8,4,8,8,8,8,8,8,4,8,8,8,8,8,8,4,8,8,8,8,4,4,8,8,8,8,8,8,4,8,8,8,8,8,8,4,8,8,8,8,8,8,1,
8,8,8,8,4,4,4,8,4,4,8,8,8,8,4,8,8,4,8,4,8,8,4,8,4,1



};
//###########End of Titanic#############//

    for (int thisNote = 0; thisNote < (sizeof(Titanic_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / Titanic_duration[thisNote];//convert duration to time delay
    tone(buzPin, Titanic_note[thisNote], noteDuration,BUZZER_CHANNEL);
    int pauseBetweenNotes = noteDuration * 2.70;
    delay(pauseBetweenNotes);
    noTone(buzPin,BUZZER_CHANNEL); //stop music on pin 8 
    }
}

void Play_CrazyFrog()
{
  //##############**"Crazy Frog" song of Crazy frog album**##############//
int CrazyFrog_note[] = {
  NOTE_D4, 0, NOTE_F4, NOTE_D4, 0, NOTE_D4, NOTE_G4, NOTE_D4, NOTE_C4,
  NOTE_D4, 0, NOTE_A4, NOTE_D4, 0, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_D4, NOTE_A4, NOTE_D5, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_A3, NOTE_E4, NOTE_D4,
  0,NOTE_D4,NOTE_D4
};
int CrazyFrog_duration[] = {
  8, 8, 6, 16, 16, 16, 8, 8, 8, 
  8, 8, 6, 16, 16, 16, 8, 8, 8,
  8, 8, 8, 16, 16, 16, 16, 8, 8, 2,
  8,4,4
};
//###########End of Crazy Frog#############//

  for (int thisNote = 0; thisNote < (sizeof(CrazyFrog_note)/sizeof(int)); thisNote++) {
    int noteDuration = 1000 / CrazyFrog_duration[thisNote]; //convert duration to time delay
    tone(buzPin, CrazyFrog_note[thisNote], noteDuration,BUZZER_CHANNEL);
    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(buzPin,BUZZER_CHANNEL); //stop music on pin 8 
    }
}


void marioMario(){
  int notes[] = {
1318, 1318, 1318, 1046, 1318, 1568, 784,
1046, 784, 659, 880, 987, 932, 880, 784,
1318, 1568, 1750, 1396, 1568, 1318, 1046, 1174, 987,
1046, 784, 659, 880, 987, 932, 880,
784, 1318, 1568, 1750, 1396, 1568, 1318, 1046, 1174, 987,
1568, 1480, 1396, 1244, 1318, 830, 880, 1046, 880, 1046, 1174,
0, 1568, 1480, 1396, 1244, 1318, 2093, 2093, 2093,
1568, 1480, 1396, 1244, 1318, 830, 880, 1046, 880, 1046, 1174, 1244, 1174, 1046,
};
int times[] = {
150, 300, 150, 150, 300, 600, 600,
450, 150, 300, 300, 150, 150, 300, 210,
210, 150, 300, 150, 150, 300, 150, 150, 450,
450, 150, 300, 300, 150, 150, 300,
210, 210, 150, 300, 150, 150, 300, 150, 150, 450,
150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150,
0, 150, 150, 150, 300, 150, 300, 150, 600,
150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 300, 450, 600,
};
int delays[] = {
150, 300, 300, 150, 300, 600, 600,
450, 450, 450, 300, 300, 150, 300, 210,
210, 150, 300, 150, 300, 300, 150, 150, 450,
450, 450, 450, 300, 300, 150, 300,
210, 210, 150, 300, 150, 300, 300, 150, 150, 600,
150, 150, 150, 300, 300, 150, 150, 300, 150, 150, 150,
300, 150, 150, 150, 300, 300, 300, 150, 600,
150, 150, 150, 300, 300, 150, 150, 300, 150, 150, 450, 450, 450, 1200,
};
for (int i = 0; i < 75; i++){
tone(buzPin, notes[i], times[i],BUZZER_CHANNEL);
delay(delays[i]/3);
}
noTone(buzPin,BUZZER_CHANNEL);
}