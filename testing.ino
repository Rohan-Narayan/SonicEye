int trigPin1 = 10;         //Trigger of Sensor 1
int echoPin1 = 11;    //Echo of Sensor 1
int trigPin2 = 8;       // Trigger of Sensor 2
int echoPin2 = 9;   // Echo of Sensor 2
int trigPin3 = 6;
int echoPin3 = 7;
int trigPin4 = 4;
int echoPin4 = 5;
int trigPin5 = 12;
int echoPin5 = 13;
long duration1, cm1, duration2, cm2, duration3, cm3, duration4, cm4, duration5, cm5;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
}
 
void loop() {
  //Read sensor value of sensor 1
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

  //Read sensor value of sensor 2
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

 pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
   
   digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin3, INPUT);
  duration3 = pulseIn(echoPin3, HIGH);

 digitalWrite(trigPin4, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin4, INPUT);
  duration4 = pulseIn(echoPin4, HIGH);

  digitalWrite(trigPin5, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin5, INPUT);
  duration5 = pulseIn(echoPin5, HIGH);
  
  // Convert the time into a distance
  cm1 = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  cm2 = (duration2/2) / 29.1;
  cm3 = (duration3/2) / 29.1;
  cm4 = (duration4/2) / 29.1;
  cm5 = (duration5/2) / 29.1;
  

  Serial.print(cm1);
  Serial.print("cm1 ");
  Serial.print(cm2);
  Serial.print("cm2 ");
  Serial.print(cm3);
  Serial.print("cm3 ");
  Serial.print(cm4);
  Serial.print("cm4 ");
  Serial.print(cm5);
  Serial.print("cm5 ");
  Serial.println();
  
  
  delay(250);
}
