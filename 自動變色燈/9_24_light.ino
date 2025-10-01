/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// the setup function runs once when you press reset or power the board
const int rLEDPin = 3;
const int gLEDPin = 7;
const int bLEDPin = 9;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  //Green
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, LOW);
  digitalWrite(bLEDPin, HIGH);
   delay(5000);

   //Yellow
  digitalWrite(rLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
  digitalWrite(bLEDPin, HIGH);
   delay(1000);

    //Red
  digitalWrite(rLEDPin, LOW);
  digitalWrite(gLEDPin, LOW);
  digitalWrite(bLEDPin, HIGH);
   delay(8000);

   
       
}
