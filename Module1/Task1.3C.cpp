static int led_pin = 13;
static int sensor_pin = 2;
static int sensor2_pin = 3;


void setup()
{
  // Set up the pin to output mode for the LED
  pinMode(led_pin, OUTPUT);
  // Set up the pin to input mode
  pinMode(sensor_pin, INPUT);

  pinMode(sensor2_pin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin),
                  ISR_sensor, CHANGE);
  
  attachInterrupt(digitalPinToInterrupt(sensor2_pin),
                  ISR_sensor, CHANGE);
  
  Serial.begin(9600);
}

void ISR_sensor()
{  
  if (digitalRead(sensor_pin) == HIGH || 
      digitalRead(sensor2_pin) == HIGH){
    digitalWrite(led_pin, HIGH);
    Serial.println("ON");

  } else
  {
  	digitalWrite(led_pin, LOW);
    Serial.println("OFF");
  }
}

void loop(){
}
