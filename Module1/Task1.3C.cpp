static int led_pin = 13;
static int sensor_pin = 2;
static int btn_pin = 3;

static bool state = false;

void setup()
{
  // Set up the pin to output mode for the LED
  pinMode(led_pin, OUTPUT);
  // Set up the pin to input mode
  pinMode(sensor_pin, INPUT);
  
  pinMode(btn_pin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(btn_pin),
                  btn_interrupt, FALLING);
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin),
                  sensor_interrupt, CHANGE);
 
  
  Serial.begin(9600);
}

void btn_interrupt()
{  
  if (state == false){
    state = true;
  	Serial.println("System ON");
    Serial.println("");
  }
  else if (state == true){
    state = false;
  	Serial.println("System OFF");
    Serial.println("");
  }   
}

void sensor_interrupt()
{  
  if (digitalRead(sensor_pin) == HIGH && state == true)
  {
    digitalWrite(led_pin, HIGH);
    Serial.println("ON");
  } else if (digitalRead(sensor_pin) == LOW &&
             state == true)
  {
  	digitalWrite(led_pin, LOW);
    Serial.println("OFF");
    Serial.println("");
  } else if (state == false && 
             digitalRead(sensor_pin) == HIGH)
  {
    Serial.println("Turn System ON");
    Serial.println("");
  }
}

void loop()
{
}
