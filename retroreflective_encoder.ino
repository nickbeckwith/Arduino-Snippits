int sensorState = HIGH;
int lastSensorState = HIGH;
int counter = 0;
float REVOLUTIONS_PER_STRIP = 1;
unsigned long dTime = 0;
float revolutions_per_minute = 0;
int AVERAGE_AMOUNT = 3;
unsigned long starting = 0;
unsigned long ending = 0;
int counter_prev = 0;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println("estimated revolutions per minute\n");
  //while (1) {Serial.println(digitalRead(3));}
  while (1) {
    sensorState = digitalRead(3);
    if (sensorState != lastSensorState) {
      if (sensorState == HIGH) {
        counter++;
      }
    }
    lastSensorState  = sensorState;
    if (counter % AVERAGE_AMOUNT == 0 && counter != counter_prev) {
      dTime = millis() - starting;
      starting = dTime + starting;
      revolutions_per_minute = float(AVERAGE_AMOUNT) * REVOLUTIONS_PER_STRIP / (float(dTime) / 60000);
      Serial.println(revolutions_per_minute);
      //starting == millis();
    }
    counter_prev = counter;
  }
}
