/*
 Code inspire by Random Nerd Tutorial
 https://randomnerdtutorials.com/esp32-hc-sr04-ultrasonic-arduino/

 Author: Teuku Ezandi Trinanda
 E-mail: ezzzandi@gmail.com
 For Electrical Engineering Design project
 With:
 1. Jabal Abdul Salam
 2. Katrin Nada
 */
//Set pin for Ultrasonic1 
#define trigPin1 14 //Set Trigger di GPIO 14
#define echoPin1 13 //Set Echo di GPIO 13

//Set pin for Ultrasonic2 
#define trigPin2 19 //Set Trigger di GPIO 19
#define echoPin2 18 //Set Echo di GPIO 18


//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

int durasiUltrasonic1, jarakUltrasonic1;
int durasiUltrasonic2, jarakUltrasonic2;

const int LED1 = 2;
const int LED2 = 4;

void ultrasonic1(){
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durasiUltrasonic1 = pulseIn(echoPin1, HIGH);
  
  // Calculate the distance
  jarakUltrasonic1 = durasiUltrasonic1 * SOUND_SPEED/2;
  Serial.print("Jarak sensor1 : ");
  Serial.println(jarakUltrasonic1);
}
void ultrasonic2(){
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durasiUltrasonic2 = pulseIn(echoPin2, HIGH);
  
  // Calculate the distance
  jarakUltrasonic2 = durasiUltrasonic2 * SOUND_SPEED/2;
  Serial.print("Jarak sensor2 : ");
  Serial.println(jarakUltrasonic2);
}

void setup() {

  pinMode(trigPin1, OUTPUT); //Set pin Trigger1 sebagai output
  pinMode(echoPin1, INPUT); //Set pin Echo1 sebagai input
  pinMode(LED1, OUTPUT); //Set LED1 sebagai output
  pinMode(trigPin2, OUTPUT); //Set pin Trigger2 sebagai output
  pinMode(echoPin2, INPUT); //Set pin Echo2 sebagai input
  pinMode(LED2, OUTPUT); //Set LED2 sebagai output
  Serial.begin(115200);
  
}

void loop() {
  ultrasonic1();
  ultrasonic2();
  
  if (jarakUltrasonic1 <= 15) { // Jarak (Cm) dapat anda sesuaikan
    digitalWrite(LED1, LOW); //LED1 mati
    delay(450); //Delay
  }
  else { //Jika jarak lebih dari yang ditentukan
    digitalWrite(LED1, HIGH); //LED1 hidup
  }

  if (jarakUltrasonic2 <= 15) { // Jarak (Cm) dapat anda sesuaikan
    digitalWrite(LED2, LOW); //LED2 mati
  } else {
    digitalWrite(LED2, HIGH); //LED2 hidup
  }
  delay(450); //Delay
}
