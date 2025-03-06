#include <Arduino.h>

#define LIGHT_SENSOR 0  // Grove Light Sensor
#define BUTTON 2        // Grove Button
#define LED 3           // Grove LED

int lightThreshold = 300;  // Adjust based on room lighting (0-1023)

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int lightLevel = analogRead(LIGHT_SENSOR);  // Read light sensor
    int buttonState = digitalRead(BUTTON);  // Read button state

    Serial.print("Light Level: ");
    Serial.println(lightLevel);

    if (lightLevel < lightThreshold || buttonState == HIGH) {  
        digitalWrite(LED, HIGH);  // Turn on LED
        Serial.println("Light ON");
    } else {
        digitalWrite(LED, LOW);  // Turn off LED
    }

    delay(500);
}