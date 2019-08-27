#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include "Button_Press.h"

// the number of the pushbutton pin
const int button_pin_1 = 2;
const int button_pin_2 = 3;
const int button_pin_3 = 4;         

// software serial
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// bool is_button_pressed(const int button_pin)
// {
//   bool is_pressed = digitalRead(button_pin);
  
//   if (is_pressed == true)
//   {
//     delay(300);
//     return true;
//   }
//   else
//     return false;
// }

void setup() {
  // debugging on serial monitor on PC screen
  Serial.begin(9600);
  
  // input button
  pinMode(button_pin_1, INPUT);
  pinMode(button_pin_2, INPUT);
  pinMode(button_pin_3, INPUT);

  // mp3 serial
  mySoftwareSerial.begin(9600);

  // mp3 module availablility check
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));


  // volume control
  myDFPlayer.volume(5);  //Set volume value. From 0 to 30
}

void loop() {

  // check which button pressed: assumption (no two buttons are pressed at the same time)
  bool is_button_1_pressed = is_button_pressed(button_pin_1);
  bool is_button_2_pressed = is_button_pressed(button_pin_2);
  bool is_button_3_pressed = is_button_pressed(button_pin_3);

  // play mp3 file according to the pressed button
  if (is_button_1_pressed == true)
  {
    Serial.println("Button 1");
    myDFPlayer.play(1);  //Play the first mp3
  }
  else if (is_button_2_pressed == true)
  {
    Serial.println("Button 2");
    myDFPlayer.play(2);  //Play the first mp3
  }
  else if (is_button_3_pressed == true)
  {
    Serial.println("Button 3");
    myDFPlayer.play(3);  //Play the first mp3
  }
}
