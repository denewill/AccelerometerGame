/**
 ============================================================================
 * @file     main.cpp
 * @brief    Demonstrates use of MMA845x Accelerometer over I2C
 *
============================================================================
 */
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "i2c.h"
#include "mma845x.h"
#include "delay.h"
#include "mcpio.h"
#include "PITlab5.h"

// Allows access to USBDM library name-space
using namespace USBDM;

/*************************************************
 * Global objects representing hardware
 **************************************************/

// I2C interface
I2c0     i2c0;

// Accelerometer via I2C
MMA845x  accelerometer(i2c0, MMA845x::AccelerometerMode_2Gmode);

/**************************************************/

static constexpr int MAX_OFFSET = 2;
static constexpr int MIN_OFFSET = -2;

/**
 * Provides an offset value that may vary by up to +/- 1 on each call.
 *
 * @return offset value in range [MIN_OFFSET .. MAX_OFFSET]
 */
int randomWalk() {
   static int offset = 0;

   switch(rand()%2) {
      case 0: offset -= 1; break;
      case 1: offset += 1; break;
   }
   if (offset < MIN_OFFSET) {
      offset = MIN_OFFSET;
   }
   if (offset > MAX_OFFSET) {
      offset = MAX_OFFSET;
   }
   return offset;
}

/*
 *Calculates the player's score
 *
 *@param[in]: unsigned data
 *@return int score value
 */
int scores(unsigned data){
	static int functionscore = 0;

	if (data == 1 || data == 8)
	{
	   console.writeln("You have lost the game.");
	   console.write("You held on for ")
	          .write(functionscore/10)
	          .writeln(" seconds.");
	   functionscore = 0;
	}
	else{
		functionscore++;
	}

	return functionscore;
}

/**
 * Report accelerometer values
 *
 * @param[in] accelerometer Accelerometer to use
 */
void report(MMA845x &accelerometer) {
   int accelStatus;
   int16_t accelX,accelY,accelZ;

   accelerometer.readAccelerometerXYZ(accelStatus, accelX, accelY, accelZ);
   console.setPadding(Padding_LeadingZeroes).setWidth(2).
         write("s=0x").write(accelStatus,Radix_16).
         setPadding(Padding_LeadingSpaces).setWidth(10).
         write(", aX=").write(accelX).
         write(", aY=").write(accelY);
}

int main() {
   console.writeln("Starting\n");
   console.write("Device ID = 0x").write(accelerometer.readID(), Radix_16).writeln("(should be 0x1A)");

   // Check if any USBDM error yet (constructors)
   checkError();
   report(accelerometer);
   console.write("Doing simple calibration\n"
         "Make sure the device is level!\n");
   waitMS(2000);

   if (accelerometer.calibrateAccelerometer() != E_NO_ERROR) {
      console.write("Calibration failed!\n");
      __asm__("bkpt");
   }

   // Make sure we have new values
   waitMS(100);
   console.write("After calibration\n");

   //Reset Output settings for GPIO
   SetOutput();
   WritePin(0x00);

   int ScoreValue = 0;
   int accelStatus;
   unsigned data = 0;
   int16_t accelX,accelY,accelZ;
   initializePIT();

   for(;;) {
	   accelerometer.readAccelerometerXYZ(accelStatus, accelX, accelY, accelZ);
	   //console.writeln(accelY);
	   data = (accelY + 3400)/850;		// recalibrate manually
	   data += randomWalk();
	   //console.writeln(data);

	   //turn on LEDs
	   switch(data)
	   {
	   case 1: WritePin(1);
	   	   	   	   break;
	   case 2: WritePin(2);
	   	   	   	   break;
	   case 3: WritePin(4);
	   	   	   	   break;
	   case 4: WritePin(8);
	   	   	  	   break;
	   case 5: WritePin(16);
	   	   	   	   break;
	   case 6: WritePin(32);
	   	   	   	   break;
	   case 7: WritePin(64);
	   	   	   	   break;
	   case 8: WritePin(128);
	   	   	   	   break;
	   }

	   //calculate score values
	   ScoreValue = scores(data);

	   //adjust duration of waits
	   SpeedAdvance(ScoreValue);
   }
}
















