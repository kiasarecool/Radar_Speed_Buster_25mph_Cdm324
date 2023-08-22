#include <Adafruit_NeoPixel.h>

#define PIN1            5 // Pin connected to the first NeoPixel ring
#define PIN2            6 // Pin connected to the second NeoPixel ring
#define NUMPIXELS      24 // Number of pixels in each ring
#define RADAR_PIN 14 // Pin connected to Cdm324 output
#define SPEED_THRESHOLD 25 // Speed threshold in mph

Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
volatile unsigned long previousTime = 0;
volatile float frequency = 0;


void setup() {
  ring1.begin();
  ring2.begin();
  ring1.show(); // Initialize all pixels to 'off'
  ring2.show();
  attachInterrupt(digitalPinToInterrupt(RADAR_PIN), calculateFrequency, RISING);

}

void loop() {
  // Calculate speed based on frequency (you will need to calibrate this relationship)
  float speed = frequency * conversionFactor; // Replace conversionFactor with your calibration

  if (speed > SPEED_THRESHOLD) {
    flashLights();
  }

  delay(100); // Delay between readings
}

void calculateFrequency() {
  unsigned long currentTime = micros();
  unsigned long timeDifference = currentTime - previousTime;
  previousTime = currentTime;

  if (timeDifference > 0) {
    frequency = 1000000.0 / timeDifference; // Frequency in Hz
  }
}


  if (speed > SPEED_THRESHOLD) {
    flashPoliceLights();
  }

  delay(100);
}

void flashPoliceLights() {
  // Flash one ring red and the other blue, then swap
  for (int j = 0; j < 10; j++) { // Number of flashes
    for (int i = 0; i < NUMPIXELS; i++) {
      ring1.setPixelColor(i, ring1.Color(255, 0, 0)); // Red color
      ring2.setPixelColor(i, ring2.Color(0, 0, 255)); // Blue color
    }
    ring1.show();
    ring2.show();
    delay(100);

    for (int i = 0; i < NUMPIXELS; i++) {
      ring1.setPixelColor(i, ring1.Color(0, 0, 255)); // Blue color
      ring2.setPixelColor(i, ring2.Color(255, 0, 0)); // Red color
    }
    ring1.show();
    ring2.show();
    delay(100);
  }

  // Turn off all LEDs after flashing
  for (int i = 0; i < NUMPIXELS; i++) {
    ring1.setPixelColor(i, ring1.Color(0, 0, 0));
    ring2.setPixelColor(i, ring2.Color(0, 0, 0));
  }
  ring1.show();
  ring2.show();
}
