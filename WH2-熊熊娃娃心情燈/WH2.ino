const int buttonPin = 2;  
const int rPin = 3;       
const int gPin = 4;       
const int bPin = 5;       


int colorValue = 128;     
unsigned long lastTime = 0;
const long interval = 30; 

bool lastButtonState = HIGH;
bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  Serial.begin(9600);
  updateColor();  
  Serial.println("W");
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  unsigned long currentTime = millis();
  
  
  if (buttonState == LOW && lastButtonState == HIGH) {
    
    colorValue -= 30;  
    if (colorValue < 0) colorValue = 0;
    
    Serial.print("butt ");
    Serial.print(colorValue + 30);
    Serial.print("跳");
    Serial.println(colorValue);
    
    updateColor(); 
  }
  
  lastButtonState = buttonState;
  
  
  if (currentTime - lastTime >= interval) {
    lastTime = currentTime;
    
    if (buttonState == HIGH) {
      
      colorValue += 3;  
      if (colorValue > 255) colorValue = 255;
      
      updateColor();
      
      
      Serial.print("B");
      Serial.print(colorValue);
      Serial.print("狀態");
      if (colorValue < 85) Serial.print("G");
      else if (colorValue < 170) Serial.print("W");
      else Serial.print("B");
      Serial.println();
    }
  }
}

void updateColor() {
  int r, g, b;
  
  if (colorValue <= 128) {
    
    float ratio = colorValue / 128.0;
    
    
    r = 255 * ratio;      
    g = 255;              
    b = 255 * ratio;      
    
  } else {
    
    float ratio = (colorValue - 128) / 127.0;
    r = 255 * (1 - ratio);  
    g = 255 * (1 - ratio);  
    b = 255;                
  }
  
  
  r = constrain(r, 0, 255);
  g = constrain(g, 0, 255);
  b = constrain(b, 0, 255);
  
  
  analogWrite(rPin, 255 - r);
  analogWrite(gPin, 255 - g);
  analogWrite(bPin, 255 - b);
}