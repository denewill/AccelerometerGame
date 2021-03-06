/**
 ============================================================================
 * @file  PITlab5.cpp
 * @brief
 * Use PIT for delay
============================================================================
 */
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

// Connection mapping - change as required
// Led is assumed active-low
using Timer        = Pit;
using TimerChannel = Timer::Channel<0>;

/*
 * Initialize PIT configurations for PIT use
 *
 * @param:-
 */
void initializePIT() {
   // Enable PIT
   Timer::configure();

   // Check for errors so far
   checkError();
}

/*
 * Adjust the duration of waits
 *
 * @param[in]: unsigned score
 */
void SpeedAdvance(unsigned score)
{
	// Delay in ticks using channel 0
    // This is a busy-waiting loop!
	switch (score/50)
	{
	case 0:
	case 1: TimerChannel::delay(100*ms);
			break;
	case 2: TimerChannel::delay(90*ms);
			console.writeln("NOW LVL 2");
			break;
	case 3: TimerChannel::delay(80*ms);
	        console.writeln("NOW LVL 3");
			break;
	case 4: TimerChannel::delay(70*ms);
	        console.writeln("NOW LVL 4");
			break;
	case 5: TimerChannel::delay(60*ms);
	        console.writeln("MAXIMUM SPEED");
			break;
	default: TimerChannel::delay(50*ms);
	        console.writeln("MAXIMUM SPEED");
			break;
	}
}
