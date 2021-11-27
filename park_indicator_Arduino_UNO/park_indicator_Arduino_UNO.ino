/*
 * Author:
 * Teuku Ezandi Trinanda
 * Kamal Adlan Riadhi
 * Muhammad Rianzi
 * 
 * Created for Embedded System Project
 * Inspired by Arduino New Ping Documentation
 */
#include <NewPing.h> //Library untuk Sensor Ultrasonic

#define trigPin1 12 //Set Trigger di Pin digital 12
#define echoPin1 13 //Set Echo di Pin digital 13

#define trigPin2 8 //Set Trigger di Pin digital 8
#define echoPin2 9 //Set Echo di Pin digital 9

#define MAX_DISTANCE 200 //Set jarak maksimal

NewPing sonar1(trigPin1, echoPin1, MAX_DISTANCE);
NewPing sonar2(trigPin2, echoPin2, MAX_DISTANCE);

const int LED1 = 2;
const int LED2 = 3;
int jarak1, jarak2;

void setup() {

  pinMode(LED1, OUTPUT); //Set LED1 sebagai output
  pinMode(LED2, OUTPUT); //Set LED2 sebagai output
  Serial.begin(9600);
  
}

void loop() {
  jarak1 = sonar.ping_cm();//Send ping, get distance in cm
  Serial.print("Ping: ");
  Serial.print(jarak1); //Print result (0 = outside set distance range)
  Serial.println("cm");

  jarak2 = sonar2.ping_cm();//Send ping, get distance in cm
  Serial.print("Ping: ");
  Serial.print(jarak2); //Print result (0 = outside set distance range)
  Serial.println("cm");

  if(jarak1<=15){ // Jarak (Cm) dapat anda sesuaikan
    digitalWrite(LED1, LOW); //LED1 mati
    delay(450); //Delay
  }  
  else{ //Jika jarak lebih dari yang ditentukan
  digitalWrite(LED1, HIGH); //LED1 hidup
  }
  
  if(jarak2<=15){ // Jarak (Cm) dapat anda sesuaikan
    digitalWrite(LED2, LOW); //LED2 mati
  }else{
  digitalWrite(LED2, HIGH); //LED2 hidup
  }
  delay(450); //Delay
  }
