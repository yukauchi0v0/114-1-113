const int buttonPin = 2;  
const int rPin = 3;       
const int gPin = 4;       
const int bPin = 5;       


int currentEffect = 0;    
unsigned long previousTime = 0;
unsigned long effectTime = 0;
bool buttonPressed = false;


int breatheBrightness = 0;
int breatheDirection = 1;
int rainbowColor = 0;
int sparkleCounter = 0;
bool blinkState = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  randomSeed(analogRead(A0));  
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  unsigned long currentTime = millis();
  
  
  if (buttonState == LOW && !buttonPressed) {
    currentEffect = random(0, 5);  
    buttonPressed = true;
    resetEffect();  
  }
  
  if (buttonState == HIGH && buttonPressed) {
    buttonPressed = false;
  }
  
  
  switch(currentEffect) {
    case 0:
      breathingEffect(currentTime);  
      break;
    case 1:
      rainbowEffect(currentTime);    
      break;
    case 2:
      sparkleEffect(currentTime);    
      break;
    case 3:
      policeEffect(currentTime);     
      break;
    case 4:
      waveEffect(currentTime);       
      break;
  }
}

void resetEffect() {
  
  breatheBrightness = 0;
  breatheDirection = 1;
  rainbowColor = 0;
  sparkleCounter = 0;
  blinkState = false;
  setColor(HIGH, HIGH, HIGH);  
}


void breathingEffect(unsigned long currentTime) {
  if (currentTime - effectTime >= 20) {
    effectTime = currentTime;
    
    breatheBrightness += breatheDirection * 3;
    
    if (breatheBrightness >= 255) {
      breatheBrightness = 255;
      breatheDirection = -1;
    } else if (breatheBrightness <= 0) {
      breatheBrightness = 0;
      breatheDirection = 1;
    }
    
    
    analogWrite(rPin, 255 - breatheBrightness);
    analogWrite(gPin, 255 - breatheBrightness);
    analogWrite(bPin, 255 - breatheBrightness);
  }
}


void rainbowEffect(unsigned long currentTime) {
  if (currentTime - effectTime >= 300) {
    effectTime = currentTime;
    
    rainbowColor = (rainbowColor + 1) % 6;
    
    switch(rainbowColor) {
      case 0: setColor(LOW, HIGH, HIGH); break;  
      case 1: setColor(LOW, LOW, HIGH); break;   
      case 2: setColor(HIGH, LOW, HIGH); break;  
      case 3: setColor(HIGH, LOW, LOW); break;   
      case 4: setColor(HIGH, HIGH, LOW); break;  
      case 5: setColor(LOW, HIGH, LOW); break;   
    }
  }
}


void sparkleEffect(unsigned long currentTime) {
  if (currentTime - effectTime >= 100) {
    effectTime = currentTime;
    
    sparkleCounter++;
    if (sparkleCounter >= 5) {  
      sparkleCounter = 0;
      int randomColor = random(0, 6);
      
      switch(randomColor) {
        case 0: setColor(LOW, HIGH, HIGH); break;  
        case 1: setColor(HIGH, LOW, HIGH); break;  
        case 2: setColor(HIGH, HIGH, LOW); break;  
        case 3: setColor(LOW, LOW, HIGH); break;   
        case 4: setColor(LOW, HIGH, LOW); break;   
        case 5: setColor(HIGH, LOW, LOW); break;   
      }
    } else {
      setColor(HIGH, HIGH, HIGH);  
    }
  }
}


void policeEffect(unsigned long currentTime) {
  if (currentTime - effectTime >= 200) {
    effectTime = currentTime;
    blinkState = !blinkState;
    
    if (blinkState) {
      setColor(LOW, HIGH, HIGH);  
    } else {
      setColor(HIGH, HIGH, LOW);  
    }
  }
}


void waveEffect(unsigned long currentTime) {
  if (currentTime - effectTime >= 20) {
    effectTime = currentTime;
    
    static int wavePosition = 0;
    wavePosition = (wavePosition + 1) % 768;  
    
    int r, g, b;
    
    
    if (wavePosition < 256) {
      r = 255 - wavePosition;
      g = wavePosition;
      b = 0;
    } else if (wavePosition < 512) {
      r = 0;
      g = 255 - (wavePosition - 256);
      b = wavePosition - 256;
    } else {
      r = wavePosition - 512;
      g = 0;
      b = 255 - (wavePosition - 512);
    }
    
    
    analogWrite(rPin, 255 - r);
    analogWrite(gPin, 255 - g);
    analogWrite(bPin, 255 - b);
  }
}


void setColor(int red, int green, int blue) {
  digitalWrite(rPin, red);
  digitalWrite(gPin, green);
  digitalWrite(bPin, blue);
}