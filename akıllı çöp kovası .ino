#include <Servo.h>   
#include <Arduino.h>
Servo servo;
int triggerPin = 5;
int echoPin = 6;
int servoPin = 7;
long zaman;
int mesafe ;
void setup()
{
  servo.attach(servoPin);
  servo.write(0);
  delay(500);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){ 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  zaman= pulseIn(echoPin, HIGH);  
  mesafe = zaman* 0.034 / 2;  
  Serial.print("Mesafe: ");
  Serial.println(mesafe);
  if ( mesafe > 50 ){  
    servo.write(135);
    delay(500);  
  }else{   
    servo.write(45);
  }
