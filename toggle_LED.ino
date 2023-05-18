
const unsigned int BTN_PIN = 7;
const unsigned int LED_PIN = 3;

bool ledState = LOW;  // LED state 
bool curBtn = LOW;    // current button state
bool lastBtn = LOW;   // previous button state

void setup(){
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void buttonDown(){
  Serial.println("Button Down");
  ledState = !ledState;
  delay(100);
}

void buttonPressed(){

}

void buttonUp(){
  Serial.println("Button Up");
  delay(100);
}

void loop(){
  lastBtn = curBtn;
  curBtn = digitalRead(BTN_PIN);  // check Button

  // Button Events 
  if (lastBtn == LOW && curBtn == HIGH)
    buttonDown();
  if (lastBtn == HIGH && curBtn == HIGH) 
    buttonPressed();
  if (lastBtn == HIGH && curBtn == LOW)
    buttonUp();

  digitalWrite(LED_PIN, ledState);  // update LED
}
