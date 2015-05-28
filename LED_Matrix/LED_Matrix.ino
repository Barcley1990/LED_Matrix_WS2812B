/*
 * LED_Matrix.ino
 *
 * Created: 5/28/2015 2:21:42 PM
 * Author: Tobias Nuss
 */ 
#include "FastLED.h"
#include "smartmatrix_t3.h"

#define LED_PIN  3

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS 64

const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 16;


uint16_t XY( uint8_t x, uint8_t y)
{
	uint16_t i;
	if( y & 0x01) {
		// Odd rows run backwards
		uint8_t reverseX = (kMatrixWidth - 1) - x;
		i = (y * kMatrixWidth) + reverseX;
		} else {
		// Even rows run forwards
		i = (y * kMatrixWidth) + x;
	}
	return i;
}

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* leds( leds_plus_safety_pixel + 1);



void setup()
{
	FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
	FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
	DrawOneFrame( millis()/65536, ((int32_t)cos16( millis() * (27/1) ) * (350 / kMatrixWidth))/32768, ((int32_t)cos16( millis() * (39/1) ) * (310 / kMatrixHeight))/32768);	
	SayHello();
}



void DrawOneFrame( byte startHue8, int8_t yHueDelta8, int8_t xHueDelta8)
{
	byte lineStartHue = startHue8;
	for( byte y = 0; y < kMatrixHeight; y++) 
	{
		lineStartHue += yHueDelta8;
		byte pixelHue = lineStartHue;
		for( byte x = 0; x < kMatrixWidth; x++) 
		{
			pixelHue += xHueDelta8;
			leds[ XY(x, y)]  = CHSV( pixelHue, 255, 255);
		}
	}
	if( millis() < 5000 ) 
		FastLED.setBrightness( scale8( BRIGHTNESS, (millis() * 256) / 5000));
	else 
		FastLED.setBrightness(BRIGHTNESS);
	FastLED.show();
}

void SayHello()
{

}



