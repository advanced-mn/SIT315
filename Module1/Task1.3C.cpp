static int led_pin = 13;
static int sensor_pin = 2;
static int sensor2_pin = 3;

bool state = false;

void setup()
{
  // Set up the pin to output mode for the LED
  pinMode(led_pin, OUTPUT);
  // Set up the pin to input mode
  pinMode(sensor_pin, INPUT);
  
  pinMode(sensor2_pin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor2_pin),
                  sensor_interrupt, CHANGE);
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin),
                  sensor_interrupt, CHANGE);
 
  
  Serial.begin(9600);
}


void sensor_interrupt()
{  
  state = !state;
  
  if (state == true)
  {
    digitalWrite(led_pin, HIGH);
    Serial.println("ON");
  } else if (state == false)
  {
  	digitalWrite(led_pin, LOW);
    Serial.println("OFF");
    Serial.println("");
  }
}

void loop()
{
}
