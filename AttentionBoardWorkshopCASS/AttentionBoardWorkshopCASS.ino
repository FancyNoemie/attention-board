/*******************************************************************************

  ,---.    ,--.    ,--.                   ,--.  ,--.                   ,-----.                           ,--. 
 /  O  \ ,-'  '-.,-'  '-. ,---. ,--,--, ,-'  '-.`--' ,---. ,--,--,     |  |) /_  ,---.  ,--,--.,--.--. ,-|  | 
|  .-.  |'-.  .-''-.  .-'| .-. :|      \'-.  .-',--.| .-. ||      \    |  .-.  \| .-. |' ,-.  ||  .--'' .-. | 
|  | |  |  |  |    |  |  \   --.|  ||  |  |  |  |  |' '-' '|  ||  |    |  '--' /' '-' '\ '-'  ||  |   \ `-' | 
`--' `--'  `--'    `--'   `----'`--''--'  `--'  `--' `---' `--''--'    `------'  `---'  `--`--'`--'    `---'  

Le Jardin de l'attention
Noémie Carrier
Hiver 2025

Here is the code needed for the device we developped together for CASS's KiCAD workshop at Concordia

Voici le code dévoloppé pour votre tableau. Pour accéder aux instructions, visitez https://github.com/FancyNoemie/attention-board


Attention Board © 2024 by Noémie Carrier is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International 
*******************************************************************************/

//Il est possible de changer les délais, en minutes, de chaque bouton.
int duration[5] = { 
  60, 20, 1, 2, 3 //<-- Par exemple: {60, 20, 1380, 1380, 1380} donne {1h , 20min , 23h , 23h , 23h}
  }; 

//Variables de temps:
int now = 0;
unsigned long min = 0;
int futureTime[5];
int pressed[5];

//Assignations aux "pin" du arduino
const int led[5] = {5,6,9,10,11}; //PWM Wave pour tamiser les lumières
int button[5] = {2,4,7,12,14}; // Pin digitales
int butTone[5] = {262,294,330,349,392}; //Buzzer sur la pin 8

// Mélodie utilisée au démarrage:
#include "pitches.h"

int melody[] = { NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_C5 };
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = { 8, 8, 8, 8, 8, 8 };

//************************************************************************
void setup() {
  Serial.begin(9600);

    for (int i = 0; i < 5; i++) {
    pinMode(button[i], INPUT_PULLUP);  //configure pin 2 as an input and enable the internal pull-up resistor
    pinMode(led[i], OUTPUT);            // initialize the LED pin as an output
    digitalWrite(led[i], HIGH);         // turn LED on
    delay(100);
    digitalWrite(led[i], LOW);         // turn LED on
  }
  delay(1000);

//MÉLODIE
      for (int thisNote = 0; thisNote < 6; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }

  for (int i =0;i<5;i++){
    digitalWrite(led[i], HIGH);   // turn LED on
  }
}

void loop() {
  
  
  for (int i =0;i<5;i++){
    int etatButton = digitalRead(button[i]);
    
    if (etatButton == LOW) {  // check if the pushbutton is pressed. If it is, the buttonState is LOW.
    tone(8,butTone[i],8);
    digitalWrite(led[i], HIGH);   // turn LED on
      if (digitalRead(led[i])){
        futureTime[i] = min+duration[i];
      }
    }
    if (futureTime[i]<=min){
      digitalWrite(led[i], HIGH);   // turn LED on
    } else {
      digitalWrite(led[i], LOW);    // turn LED off
    }
  }

  if (now >= 10000){
    min++;
    now = 0;
  }else{
    now++;
  }
  Serial.println(now);
}
