// Autonomous Grass Cutting Robot
// Author: Rishabh Yadav

#define trigPin 9
#define echoPin 10

#define ENA 6
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define CUTTER 8   // Cutter motor via relay

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(CUTTER, OUTPUT);

  digitalWrite(CUTTER, LOW); // Cutter OFF initially
}

void loop() {
  distance = measureDistance();

  if (distance > 20) {
    moveForward();
    digitalWrite(CUTTER, HIGH);  // Grass cutting ON
  } else {
    stopRobot();
    digitalWrite(CUTTER, LOW);   // Cutter OFF
    delay(500);
    turnRight();
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(400);
}

