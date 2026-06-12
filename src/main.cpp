#include <Arduino.h>
#include "jump.h"




void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
  

//Two led object to start off with
digitalWrite(lights[noteOne.getPos()], HIGH);
digitalWrite(lights[noteTwo.getPos()], HIGH);
}



void loop() {

  int buttonState = digitalRead(button);

  if (millis() - lastTime >= timeDelay) {
    lastTime = millis();



  traverse(noteOne, buttonState);
  traverse(noteTwo, buttonState);

  


  };




  Serial.println(score);

}
