static int led_pin = 13;
static int sensor_pin = 2;

void setup()
{

  
  // Set up the pin to output mode for the LED
  pinMode(led_pin, OUTPUT);
  // Set up the pin to input mode
  pinMode(sensor_pin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin),
                  ISR_sensor, CHANGE);
  
  Serial.begin(9600);
}

void loop()
{
}

void ISR_sensor()
{
  if (digitalRead(led_pin) == LOW){
    digitalWrite(led_pin, HIGH);
  } else
  {
  	digitalWrite(led_pin, LOW);
    Serial.println("OFF");
  }
}

