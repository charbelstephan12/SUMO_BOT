// this value should be changed after making some tests 
long distanceToAttack=120;

// motor pin recognision 
int motorPin1 = 5;
int motorPin2 = 6;
int motorPin3 = 9;
int motorPin4 = 10;

// Utlrasonic sensor pins 
long centimeters = 0; // this a variable used to calculate the distance using the ultrasonic sensor in centimeters 
const int TrigPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11; // Echo Pin of the Ultrasonic Sensor 

// enA & enB shouldn't be connected 
int enA = 13;
int enB = 8;

// for frontSensor1Pin / frontSensor2Pin / backSensor1Pin / backSensor2Pin; We should only connect the analog pins and not the digital pins 
const int frontSensor1Pin = A0;
const int frontSensor2Pin = A1;
const int backSensor1Pin = A2;
const int backSensor2Pin = A3;

// convert form microseconds to centimeters 
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
} 

// mesure the distance using the Ultrasonic sensor 
void ultra() {
  long duration, inches, cm;
  pinMode(TrigPin, OUTPUT);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  centimeters = microsecondsToCentimeters(duration);
  Serial.print(centimeters);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

// used when the frontSensors are activated 
void backward(){
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
// used when the backSensors are activated 
void forward(){
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
// Search for enemy 
void search(){
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(motorPin1, HIGH); 
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
// the enemy was found, Hence we should attack 
void attack(){
    digitalWrite(enA, HIGH);
    digitalWrite(enB, HIGH);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}

// this void merge both voids attack() and search()
void detection(){
  ultra();
  if (centimeters < distanceToAttack) {
    attack();
  }
  else {
    search();
  }
  delay(100);
}


void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  
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

// Check for frontSensors 
  if (frontSensor1Value == 1 || frontSensor2Value == 1 ) {
	backward();
    delay(5000);
  }
// Check for backSensors 
  if (backSensor1Value == 1 || backSensor2Value == 1) {
    forward();
    delay(5000);
  }

// All sensors aren't activated then we can start the detection 
  if (frontSensor1Value == 0 && frontSensor2Value == 0 &&
      backSensor1Value == 0 && backSensor2Value == 0) {
    detection();
  }

  delay(100);
}
