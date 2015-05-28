/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Micro, Platform=avr, Package=arduino
*/

#define __AVR_ATmega32u4__
#define __AVR_ATmega32U4__
#define USB_VID 0x2341
#define USB_PID 0x8037
#define USB_MANUFACTURER 
#define USB_PRODUCT "\"Arduino Micro\""
#define ARDUINO 160
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

uint16_t XY( uint8_t x, uint8_t y);
//
//
void DrawOneFrame( byte startHue8, int8_t yHueDelta8, int8_t xHueDelta8);
void SayHello();

#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\micro\pins_arduino.h" 
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include <LED_Matrix.ino>
#include <FastLED.cpp>
#include <FastLED.h>
#include <FastSPI_LED2.h>
#include <block_clockless.h>
#include <chipsets.h>
#include <clockless.h>
#include <clockless2.h>
#include <clockless_arm_k20.h>
#include <clockless_arm_sam.h>
#include <clockless_trinket.h>
#include <color.h>
#include <colorpalettes.cpp>
#include <colorpalettes.h>
#include <colorutils.cpp>
#include <colorutils.h>
#include <controller.h>
#include <delay.h>
#include <dmx.h>
#include <fastpin.h>
#include <fastpin_arm_k20.h>
#include <fastpin_arm_sam.h>
#include <fastpin_avr.h>
#include <fastspi.h>
#include <fastspi_arm_k20.h>
#include <fastspi_arm_sam.h>
#include <fastspi_avr.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <hsv2rgb.cpp>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.cpp>
#include <lib8tion.h>
#include <noise.cpp>
#include <noise.h>
#include <pixeltypes.h>
#include <power_mgt.cpp>
#include <power_mgt.h>
#include <smartmatrix_t3.h>
