#include <Servo.h>

#define trigPin 8
#define echoPin 9

float Duration = 0;
float Distance = 0;

Servo servo;

void setup() {
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  
  servo.attach(10, 500, 2400);
  pinMode(10, OUTPUT);
}


void loop() {
  digitalWrite(trigPin,LOW);     
  delayMicroseconds(2);
 
  digitalWrite(trigPin,HIGH);  
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
 
  Duration = pulseIn(echoPin,HIGH);  
  
  Duration = Duration / 2;               
  Distance = Duration*340*100/1000000;  
  
  Serial.print("距離 ");              
  Serial.print(Distance);
  Serial.println(" cm");
  
  delay(100);

 if(Distance >= 5.00){
  servo.write(90);
  delay(1000);
 }else{
  delayMicroseconds(2);
  servo.write(0);
  delay(1000);
 }
 
  delay(1000);
}
