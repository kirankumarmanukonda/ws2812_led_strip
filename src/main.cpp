/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-ws2812b-led-strip
 */
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN_WS2812B 26  // The ESP32 pin GPIO16 connected to WS2812B
#define NUM_PIXELS 12   // The number of LEDs (pixels) on WS2812B LED strip

Adafruit_NeoPixel ws2812b(NUM_PIXELS, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

void setup() 
{
  ws2812b.begin();  // initialize WS2812B strip object (REQUIRED)
  ws2812b.clear();

  Serial.begin(115200);
  Serial.print("Hi\n");
  Serial.println("Red     -- 1");
  Serial.println("Green   -- 2");
  Serial.println("Blue    -- 3");

}

void loop() 
{
  while (Serial.available() == 0);
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    int color = Serial.parseInt();
    if(!color)
    {
      ws2812b.fill(ws2812b.Color(0, 0, 0), 0, NUM_PIXELS);
      ws2812b.show();
    }
    else if (color == 1)
    {
      // turn on all pixels to red at the same time for two seconds
      ws2812b.fill(ws2812b.Color(255, 0, 0), 0, NUM_PIXELS);
      ws2812b.show();
    }
    else if (color == 2)
    {
      ws2812b.fill(ws2812b.Color(0, 255, 0), 0, NUM_PIXELS);
      ws2812b.show();
    }
    else if (color == 3)
    {
      ws2812b.fill(ws2812b.Color(0, 0, 255), 0, NUM_PIXELS);
      ws2812b.show(); // Update the strip to show the new colors
    }

    
  }

  /*
  ws2812b.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called

  // turn pixels to green one-by-one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {         // for each pixel
    ws2812b.setPixelColor(pixel, ws2812b.Color(0, 255, 0));  // it only takes effect if pixels.show() is called
    ws2812b.show();                                          // update to the WS2812B Led Strip

    delay(500);  // 500ms pause between each pixel
  }

  // turn off all pixels for two seconds
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(2000);     // 2 seconds off time

  // turn on all pixels to red at the same time for two seconds
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {         // for each pixel
    ws2812b.setPixelColor(pixel, ws2812b.Color(255, 0, 0));  // it only takes effect if pixels.show() is called
  }
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(1000);     // 1 second on time

  // turn off all pixels for one seconds
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(1000);     // 1 second off time
  */
}
