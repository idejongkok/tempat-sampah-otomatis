#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 5;   //pin trigger sensor
int echoPin = 6;   //pin echo sensor
int servoPin = 7;  //pin sinyal servo
int led= 10;  //pin LED di arduino
long duration, dist, average;   
long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0); // biar pas dinyalain nutup dulu
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    // jarak
}
void loop() { 
  for (int i=0;i<=2;i++) {  //jarak rata2
    measure();               
   aver[i]=dist;            
    delay(10);    //delay pas tiap sis sensor ngukur
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist<50 ) {
// ganti jaraknua terserah mau brp
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}
Serial.print(dist);
}