const int motorPin1 = 8;
const int motorPin2 = 9;
const int enablePin = 10;
const int potPin = A0;
const int redLedPin = 11;
const int greenLedPin = 12;

unsigned long runTime = 10000; // run time in milliseconds
unsigned long startTime;
bool isRunning = false;
bool shouldBlink = false;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  digitalWrite(redLedPin, HIGH); // Red LED on initially
  digitalWrite(greenLedPin, LOW); // Green LED off initially

  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  unsigned long currentMillis = millis();

  if (!isRunning && currentMillis - startTime >= runTime) {
    isRunning = true;
    startTime = currentMillis;
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(enablePin, motorSpeed);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    shouldBlink = false;
  }

  if (isRunning) {
    if (currentMillis - startTime >= runTime) {
      isRunning = false;
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(enablePin, LOW);
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
    } else if (currentMillis - startTime >= runTime - 10000) {
      if (!shouldBlink) {
        shouldBlink = true;
        startTime = currentMillis;
      }
      digitalWrite(greenLedPin, millis() % 500 < 250 ? HIGH : LOW);
    }
  }
}
