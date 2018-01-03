#include <Servo.h>
Servo myServo;
const int switchPin = 2;
int servoPos = 0; 
//counter for servo switch button
int servoIndex = 0;

int ledSwitchState = 0;
int servoSwitchState = 0;
int servoState = 0; //current state of button
int servoStateLast = 0; //previous state of button
int notes[] = {262, 294, 330, 349};
void setup() {
  // set LED pins as output, switch1 as input
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
  
  // set up servo motor
  myServo.attach(9);
}

void loop() {
  //Servo motor controls
  myServo.write(servoPos);
  servoSwitchState = digitalRead(2);
  
  if(servoSwitchState != servoStateLast){ 
    if(servoSwitchState == HIGH){
      servoPos += 20;
      //set servoIndex to 0 if it reaches max of array
      if(servoPos > 179) servoPos = 0;
    
      }
  }
    servoPos += 20;
    //set servoIndex to 0 if it reaches max of array
    if(servoPos > 179) servoPos = 0;
  
  servoStateLast = servoSwitchState;
  delay(50);
  
  //Led Controls
  ledSwitchState = digitalRead(7);
  if(ledSwitchState == LOW){ //switch is off
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    //tone(8, notes[0]);
    
  }else{ //switch is toggled on
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    tone(8, notes[1]);

    delay(250); //wait a quarter second
    tone(8, notes[2]);
    //toggle LEDs
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(1000);
    tone(8, notes[3]);
    noTone(8);
  
  }

}
