int REDPin        = 6;    // RED pin of the LED to PWM pin 6
int GREENPin      = 5;    // GREEN pin of the LED to PWM pin 5
int BLUEPin       = 3;    // BLUE pin of the LED to PWM pin 3


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

