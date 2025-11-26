const int buttonPin = 2;  
const int rPin = 3;       
const int gPin = 4;       
const int bPin = 5;       


int mode = 0;             
int ledState = LOW;
unsigned long previousMillis = 0;


const long slowInterval = 1000;    
const long mediumInterval = 500;   
const long fastInterval = 200;     

bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  
  setColor(LOW, LOW, LOW);  
  Serial.begin(9600);
  Serial.println("恆亮");
}

void loop() {
  int currentButtonState = digitalRead(buttonPin);
  unsigned long currentMillis = millis();
  
  
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    mode++;
    if (mode > 3) {
      mode = 0;  
    }
    
    
    Serial.print("切");
    switch(mode) {
      case 0: 
        Serial.println("恆");
        setColor(LOW, LOW, LOW);  
        break;
      case 1: 
        Serial.println("慢"); 
        setColor(LOW, LOW, LOW);  
        ledState = HIGH;
        previousMillis = currentMillis;
        break;
      case 2: 
        Serial.println("中");
        setColor(LOW, LOW, LOW);  
        ledState = HIGH;
        previousMillis = currentMillis;
        break;
      case 3: 
        Serial.println("快");
        setColor(LOW, LOW, LOW);  
        ledState = HIGH;
        previousMillis = currentMillis;
        break;
    }
  }
  
  lastButtonState = currentButtonState;
  
  
  switch(mode) {
    case 0: 
      setColor(LOW, LOW, LOW);
      break;
      
    case 1: 
      if (currentMillis - previousMillis >= slowInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        if (ledState) {
          setColor(LOW, LOW, LOW);  
        } else {
          setColor(HIGH, HIGH, HIGH); 
        }
      }
      break;
      
    case 2: 
      if (currentMillis - previousMillis >= mediumInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        if (ledState) {
          setColor(LOW, LOW, LOW);  
        } else {
          setColor(HIGH, HIGH, HIGH); 
        }
      }
      break;
      
    case 3: 
      if (currentMillis - previousMillis >= fastInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        if (ledState) {
          setColor(LOW, LOW, LOW);  
        } else {
          setColor(HIGH, HIGH, HIGH); 
        }
      }
      break;
  }
}


void setColor(int red, int green, int blue) {
  digitalWrite(rPin, red);
  digitalWrite(gPin, green);
  digitalWrite(bPin, blue);
}