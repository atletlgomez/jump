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

  // score immediately when button is pressed
  static int lastButtonState = HIGH;

  if (lastButtonState == HIGH && buttonState == LOW) {
    if (noteOne.getPos() == 1 || noteTwo.getPos() == 1) {
      score++;
      Serial.print("Score: ");
      Serial.println(score);
    }
  }

  lastButtonState = buttonState;

  // move lights only every 700ms
  if (millis() - lastTime >= timeDelay) {
    lastTime = millis();

    traverse(noteOne, buttonState);
    traverse(noteTwo, buttonState);

    Serial.print("First Light ");
    Serial.println(noteOne.getPos());

    Serial.print("Second Light ");
    Serial.println(noteTwo.getPos());
  }
}
