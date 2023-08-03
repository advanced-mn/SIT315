static int echo_pin = 5;
static int tri_pin = 4;

static int led_pin = 13;
static int sensor_pin = 2;

void setup()
{
  // Set up the pin to output mode for the LED
  pinMode(led_pin, OUTPUT);
  // Set up the pin to input mode
  pinMode(sensor_pin, INPUT);
  
  // led and temp set up
  pinMode(tri_pin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo_pin, INPUT); // Sets the echoPin as an Input
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin),
                  ISR_sensor, CHANGE);
  
  Serial.begin(9600);
}

void loop(){}

void ultrasonic(){
  float distance;
  float duration;
  
  digitalWrite(tri_pin, LOW);
  digitalWrite(tri_pin, HIGH);
  digitalWrite(tri_pin, LOW);

  
  // Measure the pulse duration on the ECHO pin
  duration = pulseIn(echo_pin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
}

void ISR_sensor()
{  
  if (digitalRead(led_pin) == LOW){
    digitalWrite(led_pin, HIGH);
    Serial.println("ON");
    ultrasonic();
  } else
  {
  	digitalWrite(led_pin, LOW);
    Serial.println("OFF");
  }
}
