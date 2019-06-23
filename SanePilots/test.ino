// This #include statement was automatically added by the Particle IDE.
#include <Grove_4Digit_Display.h>
// updated for testing

// This #include statement was automatically added by the Particle IDE.
#include <Grove-Ultrasonic-Ranger.h>
#include "Grove_4Digit_Display.h"
#define CLK D2//pins definitions for TM1637 and can be changed to other ports
#define DIO D3



/***************************************************************************/
//	Function: Measure the distance to obstacles in front and print the distance
//			  value to the serial terminal.The measured distance is from
//			  the range 0 to 400cm(157 inches).
//	Hardware: Grove - Ultrasonic Ranger
//	Arduino IDE: Arduino-1.0
/*****************************************************************************/
//int Ultrasonic = D5;

Ultrasonic ultrasonic(D4);
TM1637 disp(CLK,DIO);





void setup()
{
	Serial.begin(9600);
	
	disp.init();
	//Options are: BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    //disp.set(BRIGHT_TYPICAL);
	disp.set(BRIGHTEST);
	
    
}
void loop()
{
    //int range;
	int digit;
    int pos = 3;
	long lastRange;
	//int lastRange;
	long RangeInCentimeters;
	
	Serial.println("The distance to obstacles in front is: ");
	RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
	Serial.print(RangeInCentimeters);//0~400cm
	Serial.println(" cm");
	delay(500);
	
	if (RangeInCentimeters != lastRange) {
    lastRange = RangeInCentimeters;

    // Fill display with zeros
    for (int i = 0; i < 4; i++) {
    disp.display(i, 0);
    }

    // Extract each digit from the range and write it to the display
    while (RangeInCentimeters >= 1) {
    // Get the current digit by performing modulo (%) division on the range
    digit  = RangeInCentimeters % 10;
    // Remove the trailing digit by whole-number division
    RangeInCentimeters /= 10;

    disp.display(pos, digit);
    pos--;
}
}

	
}
