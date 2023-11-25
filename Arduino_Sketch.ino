long centimeters = 0;

int motorPin1 = 5;
int motorPin2 = 6;
int motorPin3 = 9;
int motorPin4 = 10;

int enA = 13;
int enB = 8;

const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11;

const int frontSensor1Pin = A0;
const int frontSensor2Pin = A1;

const int backSensor1Pin = A2;
const int backSensor2Pin = A3;


void ultra() {
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  centimeters = microsecondsToCentimeters(duration);
  Serial.print(centimeters);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
void backward(){
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void forward(){
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void turn(){
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, HIGH); 
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void detection(){
  ultra();
  if (centimeters < 120) {
    digitalWrite(enA, HIGH);
    digitalWrite(enB, HIGH);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  }
  else {
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, HIGH); 
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);  }
  delay(100);
}
void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(frontSensor1Pin, INPUT);
  pinMode(frontSensor2Pin, INPUT);
  pinMode(backSensor1Pin, INPUT);
  pinMode(backSensor2Pin, INPUT);
}
void loop() {
  
  int frontSensor1Value = digitalRead(frontSensor1Pin);
  int frontSensor2Value = digitalRead(frontSensor2Pin);
  int backSensor1Value = digitalRead(backSensor1Pin);
  int backSensor2Value = digitalRead(backSensor2Pin);

  if (frontSensor1Value == 1 || frontSensor2Value == 1 ) {
	backward();
    delay(5000);
  }
  if (backSensor1Value == 1 || backSensor2Value == 1) {
    forward();
    delay(5000);
  }

  if (frontSensor1Value == 0 && frontSensor2Value == 0 &&
      backSensor1Value == 0 && backSensor2Value == 0) {
    detection();
  }
  delay(100);
}
