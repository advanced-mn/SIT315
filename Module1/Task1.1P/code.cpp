// C++ code
//
void setup()
{
  // Set up the pin to output mode for the LED
  pinMode(13, OUTPUT);
  // Set up the pin to input mode
  pinMode(2, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  updateLED();
}

void updateLED()
{
  if (digitalRead(2) == HIGH){
  	digitalWrite(13, HIGH);
    Serial.println("Sensor detected");
  } else{
  	digitalWrite(13, LOW);
    Serial.println("OFF");
  }
}

