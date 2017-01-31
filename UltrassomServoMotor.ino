//Created by Leonardo Miranda 
//E-mail leonardo at srvdesk.com.br
// This example reads 1 ultrasonic for HC SR-04 standard arduino and drives a Servo Motor when detecting an obstacle by 180 degrees. Servo motor model SG90

#define trigPin 11 //Input trigger ultrasonic
#define echoPin 12 //Input echo ultrasonic
#define servo 6 //Set servo motor port 6

int graus;

Servo s;

void setup() {
  s.attach(servo); //Select servo motor
  Serial.begin (9600); //Serial to get results in screen
  pinMode(trigPin, OUTPUT); //Output Trigger
  pinMode(echoPin, INPUT); //Input Echo
}

void loop() {
  long duration, distance; //http://arduino.cc/en/Reference/Long
  digitalWrite(trigPin, LOW);  //set pin 12 with "LOW PULSE" or off
  delayMicroseconds(4); // delay 4 microseconds

  digitalWrite(trigPin, HIGH); //set pin 12 with "HIGH PULSE" or on
  delayMicroseconds(20);  //delay 20 microseconds
  digitalWrite(trigPin, LOW); //set pin 12 with "LOW PULSE"
  duration = pulseIn(echoPin, HIGH);  //pulseIn read time of distance
  
  // This calculation is based on s = v. T, remembering that time has doubled
  // because it is the round trip time of the ultrasound

  //Calculates distance of obstacle
  distance = (duration/2) / 29.1;
  if (distance >= 40 || distance <= 0){
    Serial.println("Nada ao alcance!");
  }
  //If obstacle, than movement servo motor 180 degrees
  else {
    Serial.print(distance);
    Serial.println("cm");
    s.write(180);
    graus = 180;
  }

  //Return servo motor do position 0 if no more obstacles
  delay(200);
  
  if (graus == 180) {
    Serial.println("Graus = 180");
    s.write(0);
    graus = 0;
  }
}
