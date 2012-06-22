int REDPin        = 6;    // RED pin of the LED to PWM pin 11
int GREENPin      = 5;    // GREEN pin of the LED to PWM pin 10
int BLUEPin       = 3;    // BLUE pin of the LED to PWM pin 9


void steadyRed() {
  analogWrite(REDPin, 255);
  analogWrite(GREENPin, 0);
  analogWrite(BLUEPin, 0);
}

void steadyGreen() {
  analogWrite(REDPin, 0);
  analogWrite(GREENPin, 255);
  analogWrite(BLUEPin, 0);
}

void steadyBlue() {
  analogWrite(REDPin, 0);
  analogWrite(GREENPin, 0);
  analogWrite(BLUEPin, 255);
}

void steadyYellow() {
  analogWrite(REDPin, 255);
  analogWrite(GREENPin, 255);
  analogWrite(BLUEPin, 0); 
}

void none() {
  analogWrite(REDPin, 0);
  analogWrite(GREENPin, 0);
  analogWrite(BLUEPin, 0);
}

