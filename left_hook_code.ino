#include <Servo.h>
#include <Stepper.h>

int stepsPerRev = 2048;  //stepper motor full revolution

int val;

const int dirPin = 2;
const int stepPin = 3;

const int BUTTON_PIN = 4;
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin

Servo rot;
int rotPin = 6;
Servo horiz;
int horizPin = 7;

void moveLargeStepper(int steps, bool dir) {
  digitalWrite(dirPin, dir ? HIGH : LOW);
  for (int i = 0; i < abs(steps); i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5000);  // step speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(5000);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  delay(2000);

  rot.attach(rotPin);
  delay(300);
  horiz.attach(horizPin);
  delay(300);
}

void startrun() {
  Serial.println("--------------");
  Serial.println("start");

  // set rotation
  val = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
  rot.write(0);
  delay(1000);

  horiz.write(50);  // move 424 degrees in
  delay(1100);
  horiz.write(90);
  delay(2000);

  Serial.println("moved in");

  rot.write(90);
  delay(1000);

  Serial.println("rotated");

  horiz.write(140);  // move 424 degrees out
  delay(750);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out");

  moveLargeStepper(550, false);  // 850 max
  delay(1000);

 Serial.println("moved up");

  rot.write(180);
  delay(1000);

  Serial.println("rotated");

  horiz.write(50);  // 955 degrees in
  delay(1100);
  horiz.write(90);
  delay(2000);

  Serial.println("moved in");

  rot.write(0);
  delay(1000);

  Serial.println("rotated all the way down");

  horiz.write(50); // 106 degrees in
  delay(950);
  horiz.write(90);
  delay(2000);

  Serial.println("moved in quite a bit");

  rot.write(50);
  delay(1000);

  Serial.println("rotated diagonally");

  horiz.write(130);  // 106 degrees out
  delay(300);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out slightly");

  rot.write(0);
  delay(1000);

  Serial.println("rotated back down");

  horiz.write(180);  // 1061 degrees out
  delay(1750);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out");

  moveLargeStepper(550, true);  // 850 max
  delay(1000);

  Serial.println("moved down");
  Serial.println("end of first knot");

  rot.write(180);
  delay(1000);

  // set rotation
  val = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
  rot.write(0);
  delay(1000);

  horiz.write(50);  // move 424 degrees in
  delay(1050);
  horiz.write(90);
  delay(2000);

  Serial.println("moved in");

  rot.write(90);
  delay(1000);

  Serial.println("rotated");

  horiz.write(140);  // move 424 degrees out
  delay(750);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out");

  moveLargeStepper(500, false);  // 850 max
  delay(1000);

 Serial.println("moved up");

  rot.write(180);
  delay(1000);

  Serial.println("rotated");

  horiz.write(50);  // 955 degrees in
  delay(1100);
  horiz.write(90);
  delay(2000);

  Serial.println("moved in");

  rot.write(0);
  delay(1000);

  Serial.println("rotated all the way down");

  horiz.write(50); // 106 degrees in
  delay(700);
  horiz.write(90);
  delay(2000);

  Serial.println("moved in quite a bit");

  rot.write(55);
  delay(1000);

  Serial.println("rotated diagonally");

  horiz.write(130);  // 106 degrees out
  delay(300);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out slightly");

  rot.write(0);
  delay(1000);

  Serial.println("rotated back down");

  horiz.write(180);  // 1061 degrees out
  delay(800);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out");

  moveLargeStepper(250, true);  // 850 max
  delay(1000);

  Serial.println("moved down");

  horiz.write(105);
  delay(350);
  horiz.write(90);
  delay(2000);

  Serial.println("moved out a bit more to tighten");

  rot.write(90);
  delay(1000);

  horiz.write(105);
  delay(500);
  horiz.write(90);
  delay(2000);

  Serial.println("Done");
  Serial.println("----------------");
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW) {
    Serial.println("The button is pressed");
    startrun();
  }

  // save the the last state
  lastState = currentState;
}
