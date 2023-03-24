#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

long currentMillis;

long verifyChargerToRestartTime = 0;
long verifyChargerToRestartTime2 = 1000;

#define NUM_LEDS 300

#define DATA_PIN 15

Adafruit_NeoPixel strip(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void ledTotem() {
  int count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(255, 165, 0)); // yellow | orange
    strip.show();
    count++;
  }

  count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(0, 255, 0));
    strip.show();
    count++;
  }

  count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(128, 0, 128)); // roxo
    strip.show();
    count++;
  }

  count = 0;
  
  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(0, 255, 0));
    strip.show();
    count++;
  }

  count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(0, 0, 255)); // blue
    strip.show();
    count++;
  }

  count = 0;
  
  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(0, 255, 0));
    strip.show();
    count++;
  }

  count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(255, 0, 0)); // red
    strip.show();
    count++;
  }

  count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(0, 255, 0)); // green
    strip.show();
    count++;
  }

  count = 0;

  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(255, 255, 255)); // white
    strip.show();
    count++;
  }

  count = 0;
  
  while (count <= 300) {
    strip.setPixelColor(count, strip.Color(0, 255, 0)); 
    strip.show(); 
    count++;
  }

  strip.fill(strip.Color(255, 165, 0));
  strip.show();
  delay(250);

  strip.fill(strip.Color(128, 0, 128));
  strip.show();
  delay(250);

  strip.fill(strip.Color(0, 0, 255));
  strip.show();
  delay(250);

  strip.fill(strip.Color(255, 0, 0));
  strip.show();
  delay(250);

  strip.fill(strip.Color(0, 255, 0));
  strip.show();
  delay(250);

  strip.fill(strip.Color(255, 255, 255));
  strip.show();
  delay(250);

}

void animationLeds() {
  int count = 0;

  while (count <= 720) {
    strip.setPixelColor(count, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 40, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 60, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 100, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 120, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 160, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 180, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 220, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 240, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 280, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 300, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 340, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 360, strip.Color(0, 255, 0));
    strip.setPixelColor(count - 400, strip.Color(0, 0, 0));

    strip.setPixelColor(count - 420, strip.Color(0, 0, 255));

    strip.show();
    count++;
  }
}

void animationLedsFree() {
  int count = 255;
  int reply = 0;

  while (reply <= 5) {

    while (count >= 10) {
      strip.setBrightness(count);
      strip.show();
      delay(20);
      count -= 5;
      Serial.println(count);
    }


    while (count <= 250) {
      strip.setBrightness(count);
      strip.show();
      delay(20);
      count += 5;
      Serial.println(count);
    }

    reply++;
  }

}

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
}

void loop() {
  currentMillis = millis();

  if (currentMillis - verifyChargerToRestartTime >= verifyChargerToRestartTime2) {
    verifyChargerToRestartTime = currentMillis;
    Serial.println("Loop!");
  }

  // ledTotem();

  animationLeds();

  animationLedsFree();
  
}
