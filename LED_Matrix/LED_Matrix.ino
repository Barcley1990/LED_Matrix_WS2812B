/*
 * LED_Matrix.ino
 *
 * Created: 5/28/2015 2:21:42 PM
 * Author: Tobias Nuss
 */ 

#define LED_PIN  3

#define COLOR_ORDER GRB
#define CHIPSET     WS2811

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

void DrawOneFrame( byte startHue8, int8_t yHueDelta8, int8_t xHueDelta8)
{
	byte lineStartHue = startHue8;
	for( byte y = 0; y < kMatrixHeight; y++) {
		lineStartHue += yHueDelta8;
		byte pixelHue = lineStartHue;
		for( byte x = 0; x < kMatrixWidth; x++) {
			pixelHue += xHueDelta8;
			leds[ XY(x, y)]  = CHSV( pixelHue, 255, 255);
		}
	}
}

void setup()
{
	FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
	FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
	uint32_t ms = millis();
	int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / kMatrixWidth));
	int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / kMatrixHeight));
	DrawOneFrame( ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
	if( ms < 5000 ) {
		FastLED.setBrightness( scale8( BRIGHTNESS, (ms * 256) / 5000));
		} else {
		FastLED.setBrightness(BRIGHTNESS);
	}
	FastLED.show();
}









