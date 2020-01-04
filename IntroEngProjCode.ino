/*
   Ultrasonic sensor Pins:
       VCC: +5VDC
       Trig : Trigger (INPUT) - Port Pin
       Echo: Echo (OUTPUT) - Port Pin
       GND: GND
   Left Sensor: 0
   Left Middle: 1
   Middle: 2
   Right Middle: 3
   Right Sensor: 4
*/
int trigPin[ ] = {12, 10, 8, 6, 4}; // Trigger
int echoPin[ ] = {13, 11, 9, 7, 5}; // Echo
int speakerPinLeft = {2};
int speakerPinRight = {3};
long duration[ ] = {0, 0, 0, 0, 0};
int distance [ ] = {0, 0, 0, 0, 0};
int frequency = 0;

int minimum, index;

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  minimum = 2000;
  index = -1;
  
  for (byte i = 0; i < 5; i = i + 1) {
    pinMode(trigPin[i], OUTPUT);
    pinMode(echoPin[i], INPUT);
  }
}

void loop() {
  storeDistance();
  distanceAnalysis();
  playSound(frequency, index);
  
  Serial.println();
  delay(150);
}

void storeDistance() {
  for (byte i = 0; i < 5; i = i + 1) {
    //Sending Signal
    digitalWrite(trigPin[i], LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[i], LOW);
    //Receiving Signal
    pinMode(echoPin[i], INPUT);
    //Storing as duration and distance output
    duration[i] = pulseIn(echoPin[i], HIGH);
    distance[i] = (duration[i] / 2) / 29.1;
    if (distance[i] > 2000) {
      distance[i] = 2000;
    }
    //Print value
    Serial.print(i);
    Serial.print(" - ");
    Serial.print(distance[i]);
    Serial.print(" cm\t");
  }
}

void distanceAnalysis() {
  minimum = distance[0];
  index = 0;
  for (int i = 0; i < 5; i++) {
    if (minimum > distance[i]) {
      minimum = distance[i];
      index = i;
    }
  }
  Serial.print(minimum);
  if (minimum == 2000)
    index = -1;
  
  frequency = 4000*(1/(1 + exp(0.02*(minimum - 120)))); // sigmoid function mapping
}

void playSound(int freq, int ind) {
  if (freq >= 40) {
    switch(ind) {
      case 0: case 1:
        tone(speakerPinLeft, freq, 10);
        Serial.print("\tLEFT");
        break;
      case 3: case 4:
        tone(speakerPinRight, freq, 10);
        Serial.print("\tRIGHT");
        break;
      case 2:
        tone(speakerPinLeft, freq, 9);
        delay(10);
        tone(speakerPinRight, freq, 9);
        Serial.print("\tMIDDLE");
        break;
      case -1:
        Serial.print("\tNOPE");
        break;
    }
  }
  delay(10);
}
