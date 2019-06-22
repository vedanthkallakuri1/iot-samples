Ultrasonic ultrasonic(D2);

int lastRange = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int rangeI;
    int rangeC;

    Serial.println("Obstacle found at:");

    rangeC = ultrasonic.MeasureInCentimeters();
    Serial.print(rangeC); //0~400cm
    Serial.println(" cm");

   rangeI = ultrasonic.MeasureInInches();
    Serial.print(rangeI); //0~400inches
    Serial.println(" inch");

    if (rangeI != lastRange) {
        lastRange = rangeI;

    }
         if (rangeC != lastRange) {
        lastRange = rangeC;

    }


    delay(2000);
}
