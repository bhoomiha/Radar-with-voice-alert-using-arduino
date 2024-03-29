PK
     �QX               sketch_apr11a/PK
     �QX����i   i      sketch_apr11a/sketch.json{
  "cpu": {
    "fqbn": "",
    "name": "",
    "type": ""
  },
  "secrets": [],
  "included_libs": []
}PK
     �QX'���  �     sketch_apr11a/ReadMe.adoc:Author: bhoomiha
:Email: {AuthorEmail}
:Date: 11/04/2023
:Revision: version#
:License: Public Domain

= Project: {Project}

Describe your project

== Step 1: Installation
Please describe the steps to install this project.

For example:

1. Open this file
2. Edit as you like
3. Release to the World!

== Step 2: Assemble the circuit

Assemble the circuit following the diagram layout.png attached to the sketch

== Step 3: Load the code

Upload the code contained in this sketch on to your board

=== Folder structure

....
 sketch123                => Arduino sketch folder
  ├── sketch123.ino       => main Arduino file
  ├── schematics.png      => (optional) an image of the required schematics
  ├── layout.png          => (optional) an image of the layout
  └── ReadMe.adoc         => this file
....

=== License
This project is released under a {License} License.

=== Contributing
To contribute to this project please contact bhoomiha https://id.arduino.cc/bhoomiha

=== BOM
Add the bill of the materials you need for this project.

|===
| ID | Part name      | Part number | Quantity
| R1 | 10k Resistor   | 1234-abcd   | 10
| L1 | Red LED        | 2345-asdf   | 5
| A1 | Arduino Zero   | ABX00066    | 1
|===


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents.
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
PK
     �QX�}�m	  m	     sketch_apr11a/sketch_apr11a.ino/*

*/

#include <Servo.h>
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
const int led1 = 8;
const int led2 = 9;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
 
  if (distance < 30){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("O");
}
  else{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    Serial.println("pp");
   
  }// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
 
  //Serial.print(i); // Sends the current degree into the Serial Port
  //Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  //Serial.print(distance); // Sends the distance value into the Serial Port
  //Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  if (distance < 30){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("O");
}
  else{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    Serial.println("pp");
   
  }
 // Serial.print(i);
  //Serial.print(",");
  //Serial.print(distance);
  //Serial.print(".");
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
PK 
     �QX                            sketch_apr11a/PK 
     �QX����i   i                ,   sketch_apr11a/sketch.jsonPK 
     �QX'���  �               �   sketch_apr11a/ReadMe.adocPK 
     �QX�}�m	  m	               �  sketch_apr11a/sketch_apr11a.inoPK        �    