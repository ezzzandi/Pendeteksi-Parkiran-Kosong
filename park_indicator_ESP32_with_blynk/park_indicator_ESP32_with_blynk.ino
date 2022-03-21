#define BLYNK_TEMPLATE_ID           "TMPLj8yDW3i2"
#define BLYNK_DEVICE_NAME           "Smart Parking Indicator"
#define BLYNK_AUTH_TOKEN            "EgJoKZHw8dSF-D2Q5i5U7Qj07E4exLlC"

#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "kentang";
char pass[] = "wifigratis";

//Library for ultrasonic sensors
#include <NewPing.h>

#define MAX_DISTANCE 100

//Ultrasonic for parking spot number 1
#define TRIG1 13
#define ECHO1 12

//Ultrasonic for parking spot number 2
#define TRIG2 14
#define ECHO2 27

//Ultrasonic for parking spot number 3
#define TRIG3 26
#define ECHO3 25

//Ultrasonic for parking spot number 4
#define TRIG4 33
#define ECHO4 32

WidgetLED led1(V0);
WidgetLED led2(V1);
WidgetLED led3(V2);
WidgetLED led4(V3);

//Create an object for each ultrasonic sensors
NewPing sonar1(TRIG1, ECHO1, MAX_DISTANCE);
NewPing sonar2(TRIG2, ECHO2, MAX_DISTANCE);
NewPing sonar3(TRIG3, ECHO3, MAX_DISTANCE);
NewPing sonar4(TRIG4, ECHO4, MAX_DISTANCE);

#define LED1 2 //LED indicator for ultrasonic 1
#define LED2 4 //LED indicator for ultrasonic 2
#define LED3 5 //LED indicator for ultrasonic 3
#define LED4 18 //LED indicator for ultrasonic 4

int parkingSpot1, parkingSpot2, parkingSpot3, parkingSpot4;

BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V8, "offImageUrl", "https://tnafatih.sch.id/wp-content/uploads/lOGO-Ori-web.png");
  Blynk.setProperty(V8, "onImageUrl",  "https://tnafatih.sch.id/wp-content/uploads/lOGO-Ori-web.png");
  Blynk.setProperty(V8, "url", "https://tnafatih.sch.id/");
}

void parkCheck() {
  parkingSpot1 = sonar1.ping_cm();
  parkingSpot2 = sonar2.ping_cm();
  parkingSpot3 = sonar3.ping_cm();
  parkingSpot4 = sonar4.ping_cm();

  //Checking parking spot number 1
  if (parkingSpot1 <= 10) {
    digitalWrite(LED1, LOW);
    led1.off();
    Blynk.virtualWrite(V4, "Not Available");
  }
  else {
    digitalWrite(LED1, HIGH);
    led1.on();
    Blynk.virtualWrite(V4, "Available");
  }

  //Checking parking spot number 2
  if (parkingSpot2 <= 10) {
    digitalWrite(LED2, LOW);
    led2.off();
    Blynk.virtualWrite(V5, "Not Available");
  }
  else {
    digitalWrite(LED2, HIGH);
    led2.on();
    Blynk.virtualWrite(V5, "Available");
  }

  //Checking parking spot number 3
  if (parkingSpot3 <= 10) {
    digitalWrite(LED3, LOW);
    led3.off();
    Blynk.virtualWrite(V6, "Not Available");
  }
  else {
    digitalWrite(LED3, HIGH);
    led3.on();
    Blynk.virtualWrite(V6, "Available");
  }

  //Checking parking spot number 4
  if (parkingSpot4 <= 10) {
    digitalWrite(LED4, LOW);
    led4.off();
    Blynk.virtualWrite(V7, "Not Available");
  }
  else {
    digitalWrite(LED4, HIGH);
    led4.on();
    Blynk.virtualWrite(V7, "Available");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  pinMode(TRIG1, OUTPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(TRIG4, OUTPUT);

  pinMode(ECHO1, INPUT);
  pinMode(ECHO2, INPUT);
  pinMode(ECHO3, INPUT);
  pinMode(ECHO4, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  parkCheck();
  Serial.println(parkingSpot4);
  delay(500);
}
