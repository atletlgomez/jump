# Jump (Reaction Game)

![](src/jumpgif.gif)

## HardWare:
Arduino UNO R3
BreadBoard
10 x male-to-male wires
6 x 220 ohms resistor
6 x Green LEDS
1 x Button

## Process:
I wanted to create something more interactive than a blinking light. The game tracks the user's ability to react when the led closest
to the user is pressed. Both the lights traverse in a circle like pattern. Once the button is pressed, the score will print out and increment
if timed perfectly with the light.

## Challenges

1. Two Processes concuirenty Running

As I contiinued to create this project, I realized that i must read the button state while also having the lights traverse. In a sinle loop
i found that challegning. In my first attempt at completiion, I realized that button will only read either later or earlier before the first led
is turned on.

Solution:
I searched online on how others overcame this problem, I ended up manually creating my own time delay if statement.
