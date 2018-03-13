/***********************************************************************
* FILENAME :    ENGL235_presentation.ino            
*
* DESCRIPTION :
*       Blinks pins 11,12,13 and various speeds
* 
* AUTHOR :    Andrew Peterson   START DATE :    12 Mar 18
* EMAIL : andrew@andpeterson.com
 */

#include <SimpleTimer.h> //SimpleTimer function
/*******************
 * Definitions
 *******************/

#define BLINK_PIN 13 //The Blink LED's pin
#define FAST_BLINK_PIN 12 //The Fast Blink LED's pin
#define SOS_PIN 11 //The SOS LED's pin
#define SOS_LENGTH 22 //The length of the SOSmorse array

/*******************
 * Prototypes
 *******************/
 
void blinkLED();
void fastBlink();
void SOS();

/*******************
 * Global Varaibles
 *******************/

SimpleTimer timer; //the timer to handle launching the functions
bool SOSmorse[SOS_LENGTH] = {1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0}; //an array holdig SOS in morse
int SOSptr = 0; //An iterator to loop through SOSmorse
bool blinkState = 0, fastBlinkState = 0; //The state of the blink and fastBlink LEDs


/*
 * Initialize the pins
 * Initialize the functions to run on a timer
 */
void setup() {
  DDRB = 0b11111111; //Set pinModes on pins 11,12,13
  timer.setInterval(1000, Blink); //set Blink to be called every second
  timer.setInterval(200, FastBlink); //set FastBlink to be called every 1/5 seconds
  timer.setInterval(150, BlinkSOS); //set BlinkSOS to be called every 150ms
}

/*
 * Check the timer
 */
void loop() {
  // put your main code here, to run repeatedly:
  timer.run();
}

/*
 * Inverts the BlinkState and BLINK_PIN (13) state
 */
void Blink(){
  blinkState = !blinkState; //invert BlinkState
  digitalWrite(BLINK_PIN, blinkState); //Write BLINK_PIN to BlinkState's value
}

/*
 * Inverts fastBlinkState and FAST_BLINK_PIN (12) state
 */
void FastBlink(){
  fastBlinkState = !fastBlinkState; //inverts fastBlinkState
  digitalWrite(FAST_BLINK_PIN, fastBlinkState); //Write FAST_BLINK_PIN to fastBlinkState's value
}

/*
 * Iterates through the SOSmorse array outputting its value
 * to pin SOS_PIN (11)
 */
void BlinkSOS(){
  SOSptr++; //increment the SOSptr
  //if the SOSptr excedes the length of the SOSmores array set SOSptr to 0
  if(SOSptr >= SOS_LENGTH){
    SOSptr = 0;
  }
  digitalWrite(SOS_PIN, SOSmorse[SOSptr]); //Write SOS_PIN to *SOSptr's state
}

