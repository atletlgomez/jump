#pragma once
#include "Arduino.h"


//Light Pins

const int led1 = 7;
const int led2 = 6;
const int led3 = 5;
const int led4 = 4;
const int led5 = 3;
const int led6 = 2;

const int life1 = 10;
const int life2 = 9;
const int life3 = 8;

//Button Pin
const int button = 11;


//Life light array
int lives[3] = {life1, life2, life3};

//Light Array
int lights[7] = {0, led1, led2, led3, led4, led5, led6};

//Score
int score = 0;



//LED LIGHTS
class Led {
    private:
        int interval;
        int index;
        int pos;

    public:
        Led(int interval = 0) {
            this->interval = interval;
            index = 6;
            pos = index + interval;
        };

        void setInterval(int newInterval) {
            interval = newInterval;
        };

        int getInterval() {
            return interval;
        };

        void setIndex(int newIndex) {
            index = newIndex;
        };

        int getIndex() {
            return index;
        };

        int getPos() {
            return pos;
        };

        void move() {
            if (pos > 0) {
                pos--;
            }
        }

        void reset() {
            interval = random(1, 5);
            pos = index + interval;
        }
};


//USER INPUT
const int hitNow = 1;
const int spotOn = 3;
const int hitEarlyOrLate = 1;

void perfectHit(Led &light, int buttonState) {


    if (buttonState == LOW) {
        if (light.getPos() == hitNow) {
            score += spotOn;
        } else {
            score += hitEarlyOrLate;
        }
    } 

}


//Random Interval
int rngInterval = random(1, 5);



//Traversing

void traverse(Led &light, int buttonState) {



    digitalWrite(lights[light.getPos()], LOW);



    light.move();


    if (light.getPos() == 0) {
        light.reset();
    }

    digitalWrite(lights[light.getPos()], HIGH);



}




Led noteOne;
Led noteTwo(rngInterval);

//Time
const unsigned long timeDelay = 700;
unsigned long lastTime = 0;

//test might delete later
int firstTest = noteOne.getPos();
int secondTest = noteTwo.getPos();