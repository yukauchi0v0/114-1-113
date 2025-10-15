/*
  RGB LED Controller with Button
  Controls an RGB LED with a button to change colors and direction
*/

const int ButtonPin = 2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int ledcolor = 0;
int buttonState = 0;
bool ButtonPressed = false;
const long interval = 1000;
bool ledColorOrder = true;  // true = forward, false = backward

unsigned long previousMillis = 0;

void setup() {
  pinMode(ButtonPin, INPUT);
  
  // initialize digital pins as output
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(ButtonPin);

  // Button press detection with debouncing
  if(buttonState == HIGH && !ButtonPressed){
    ledColorOrder = !ledColorOrder;  // Toggle direction
    ButtonPressed = true;
  }
  
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }

  // Timer-based color changing
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    
    if(ledColorOrder == true){  // Forward direction
      ledcolor = ledcolor + 1;
      if(ledcolor > 7) {
        ledcolor = 0;
      }
    } else {  // Backward direction
      ledcolor = ledcolor - 1;
      if(ledcolor < 0) {
        ledcolor = 7;
      }
    }
  }

  // Set LED colors based on current color state
  switch(ledcolor) {
    case 0: // Red
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
      break;
    case 1: // Green
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
      break;
    case 2: // Blue
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
      break;
    case 3: // Yellow (Red + Green)
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
      break;
    case 4: // Magenta (Red + Blue)
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
      break;
    case 5: // Cyan (Green + Blue)
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
      break;
    case 6: // White (All colors)
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
      break;
    case 7: // Off
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
      break;
  }
}