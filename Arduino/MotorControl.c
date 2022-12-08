/*Example sketch to control a stepper motor with A4988 stepper motor driver, AccelStepper library and Arduino: continuous rotation. More info: https://www.makerguides.com */

// Include the AccelStepper library:
#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
// Motor X
#define stepPin1 2
#define dirPin1  5

// Motor Y
#define stepPin2 3
#define dirPin2  6

// Motor Z
#define stepPin3 4
#define dirPin3  7

// Motor A
#define stepPin4 12
#define dirPin4  13

#define motorInterfaceType 1

#define echoPin 10 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 11 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

bool isStopped = false;

// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);
AccelStepper stepper3 = AccelStepper(motorInterfaceType, stepPin3, dirPin3);
AccelStepper stepper4 = AccelStepper(motorInterfaceType, stepPin4, dirPin4);

void setup() {
  Serial.begin(9600);
  // Declare pins as output:
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);

  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  digitalWrite(dirPin3, HIGH);
  digitalWrite(dirPin4, HIGH);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //distance = 5; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");

   if(distance <= 3)
    {
      Serial.println("STOPPED");
      isStopped = true;
    }
    else 
      isStopped = false;

  if (isStopped == false) 
  {
 // These four lines result in 1 step:
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(200);

    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(200);

    digitalWrite(stepPin3, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin3, LOW);
    delayMicroseconds(200);

    digitalWrite(stepPin4, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin4, LOW);
    delayMicroseconds(200);
  } 
  
  else 
  {
    // without calling stepper.run() function, motor stops immediately
    // NOTE: stepper.stop() function does NOT stops motor immediately
    Serial.println(F("The stepper motor is STOPPED"));
  }
}
 


