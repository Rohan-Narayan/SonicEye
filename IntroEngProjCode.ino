/*
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Port Pin
        Echo: Echo (OUTPUT) - Port Pin
        GND: GND
*/
/*
   Left Sensor: 0
   Left Middle: 1
   Middle: 2
   Right Middle: 3
   Right Sensor: 4
*/
int trigPin[ ] = {12, 10, 8, 6, 4}; // Trigger
int echoPin[ ] = {13, 11, 9, 7, 5}; // Echo
int speakerPinLeft = {1};
int speakerPinRight = {2};
long duration[ ] = {0, 0, 0, 0, 0};
long cm [ ] = {0, 0, 0, 0, 0};
//Distance thresholds in cm
/*int thresh1 = 100; //Far away
  int thresh2 = 80;
  int thresh3 = 60;
  int thresh4 = 40;
  int thresh5 = 20;
  int thresh6 = 10;
  int thresh7 = 5; //Very close
*/

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  for (byte i = 0; i < 5; i = i + 1) {
    pinMode(trigPin[i], OUTPUT);
    pinMode(echoPin[i], INPUT);
  }
}

void loop() {
  storeDistance();
  delay(250);
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
    //Storing as duration and cm output
    duration[i] = pulseIn(echoPin[i], HIGH);
    cm[i] = (duration[i] / 2) / 29.1;
    if (cm[i] > 2000) {
      cm[i] = 0;
    }
    //Print value
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("\t");
  }
  Serial.println();

}
/*
  void playSound(){
  /*
   Far Away: Slow Tempo
   Close By: Fast Tempo
*/
/*
if ((cm[0] < thresh7) || (cm[1] < thresh7)) {
  tone(speakerPinLeft, 1000, 1);
}
else if ((cm[0] < thresh7) || (cm[1] < thresh7)) {
  tone(speakerPinLeft, 442, );
}
}
*/
