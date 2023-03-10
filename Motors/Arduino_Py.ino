
#define MotorDirection1 8
#define MotorSpeed1 9
#define MotorDirection2 10
#define MotorSpeed2 11
int incomingData;
int SpeedVal = 0;
void setup() {
  pinMode(MotorDirection1, OUTPUT);
  pinMode(MotorSpeed1, OUTPUT);
  pinMode(MotorDirection2, OUTPUT);
  pinMode(MotorSpeed2, OUTPUT);
  Serial.begin(9600);
  Serial.write("Press the button to control LED (Message from Arduino");
}

void loop() {

  while (Serial.available()) {
    incomingData = Serial.read();

    
    if (incomingData == '1') {
        digitalWrite(MotorDirection1, LOW);       //Loop increases the speed slowly until it reaches max speed.
       digitalWrite(MotorDirection2, HIGH);  
  //for(SpeedVal = 0; SpeedVal < 100; SpeedVal++){
      analogWrite(MotorSpeed1,100l);
      analogWrite(MotorSpeed2,100);
  //     delay(40);
  //     }
  //    analogWrite(MotorSpeed1,0);
  //    analogWrite(MotorSpeed2,0);
 
    }
    
    if (incomingData == '0') {
        digitalWrite(MotorDirection1, HIGH);               //Loop increases the speed slowly until it reaches max speed.
       digitalWrite(MotorDirection2, LOW); 
   //for(SpeedVal = 0; SpeedVal < 100; SpeedVal++){
      analogWrite(MotorSpeed1,100);
       analogWrite(MotorSpeed2,100);
   //    delay(40);
   //  } 
   //  analogWrite(MotorSpeed1,0);
   //  analogWrite(MotorSpeed2,0);
 
    }

       if (incomingData == '3') {
        digitalWrite(MotorDirection1, HIGH);               //Loop increases the speed slowly until it reaches max speed.
       digitalWrite(MotorDirection2, HIGH); 
   //for(SpeedVal = 0; SpeedVal < 100; SpeedVal++){
      analogWrite(MotorSpeed1,100);
       analogWrite(MotorSpeed2,100);
   //    delay(40);
   //  } 
   //  analogWrite(MotorSpeed1,0);
   //  analogWrite(MotorSpeed2,0);
 
    } 

           if (incomingData == '4') {
        digitalWrite(MotorDirection1,LOW );               //Loop increases the speed slowly until it reaches max speed.
       digitalWrite(MotorDirection2, LOW); 
   //for(SpeedVal = 0; SpeedVal < 100; SpeedVal++){
      analogWrite(MotorSpeed1,100);
       analogWrite(MotorSpeed2,100);
   //    delay(40);
   //  } 
   //  analogWrite(MotorSpeed1,0);
   //  analogWrite(MotorSpeed2,0);
 
    } 

    if (incomingData == '2') {

        analogWrite(MotorSpeed1,0);
        analogWrite(MotorSpeed2,0);
     }
  }
}
