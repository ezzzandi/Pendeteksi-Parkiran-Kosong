#define trigPin1 12 //Set Trigger di Pin digital 12
#define echoPin1 13 //Set Echo di Pin digital 13
#define trigPin2 8 //Set Trigger di Pin digital 8
#define echoPin2 9 //Set Echo di Pin digital 9

int LED1 = 2;
int LED2 = 3;

void setup() {

  pinMode(trigPin1, OUTPUT); //Set pin Trigger1 sebagai output
  pinMode(echoPin1, INPUT); //Set pin Echo1 sebagai input
  pinMode(LED1, OUTPUT); //Set LED1 sebagai output
  pinMode(trigPin2, OUTPUT); //Set pin Trigger2 sebagai output
  pinMode(echoPin2, INPUT); //Set pin Echo2 sebagai input
  pinMode(LED2, OUTPUT); //Set LED2 sebagai output
  Serial.begin(9600);
}

void loop() {

  int duration, jarak;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  jarak = (duration / 2) / 29.1;

  int duration1, jarak1;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration1 = pulseIn(echoPin2, HIGH);
  jarak1 = (duration1 / 2) / 29.1;

  Serial.print(jarak);
  Serial.print(" cm  ");
  Serial.print(jarak1);
  Serial.println(" cm");

  if (jarak <= 15) { // Jarak (Cm) dapat anda sesuaikan
    digitalWrite(LED1, LOW); //LED1 mati
    delay(450); //Delay
  }
  else { //Jika jarak lebih dari yang ditentukan
    digitalWrite(LED1, HIGH); //LED1 hidup
  }

  if (jarak1 <= 15) { // Jarak (Cm) dapat anda sesuaikan
    digitalWrite(LED2, LOW); //LED2 mati
  } else {
    digitalWrite(LED2, HIGH); //LED2 hidup
  }
  delay(450); //Delay
}
