//###TEST###

#include <Adafruit_NeoPixel.h>

#define PIN D2
#define NUMPIXELS 25

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(23, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    Serial.begin(115200);
    pixels.begin();
    pinMode(14, INPUT);
}

void loop()
{
    int delayval = 5;

    Serial.println(digitalRead(14));

    if(digitalRead(14))
    for (int i = 0; i < NUMPIXELS ; i++)
    {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
        pixels.show();
        delay(delayval);
        pixels.setPixelColor(i - 2, pixels.Color(0, 0, 0));
        pixels.show();
        delay(delayval);
    }
    else
    for (int i = 0; i < NUMPIXELS ; i++)
    {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
        pixels.show();
        delay(2*delayval);
        pixels.setPixelColor(i - 2, pixels.Color(0, 0, 0));
        pixels.show();
        delay(2*delayval);
    }
}
