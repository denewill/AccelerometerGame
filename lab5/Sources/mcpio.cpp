/**
 ============================================================================
 * @file     mcpio.cpp
 * @brief    API for MCP23008 I/O port expander
 ============================================================================
 *      Author: USER
 */

#include "i2c.h"
#include "mcpio.h"

using namespace USBDM;

// Address (LSB = R/W bit)
static const unsigned I2C_ADDRESS = 0x20<<1;
static const unsigned I2C_SPEED   = 400*kHz;

// Declare I2C interface
I2c0 i2c{I2C_SPEED, I2cMode_Polled};


/*
 * Set the direction of the individual bits of the port
 * input => direction = 1
 * output => direction = 0
 *
 * @param: direction
 */
void SetDirection(uint8_t direction){
	static const uint8_t txData[] = {IODIR, direction};
	i2c.startTransaction();
	i2c.transmit(I2C_ADDRESS, sizeof(txData), txData);
	i2c.endTransaction();
}


/*
 * Set direction as input
 *
 * @param:-
 */
void SetInput(){
	static const uint8_t txData[] = {IODIR, 0xFF};
	i2c.startTransaction();
	i2c.transmit(I2C_ADDRESS, sizeof(txData), txData);
	i2c.endTransaction();
}


/*
 * Set direction as output
 *
 * @param:-
 */
void SetOutput(){
	static const uint8_t txData[] = {IODIR, 0x00};
	i2c.startTransaction();
	i2c.transmit(I2C_ADDRESS, sizeof(txData), txData);
	i2c.endTransaction();
}


/*
 * Read pins that are set as inputs
 *
 * @param:-
 */
void ReadPin(){
	static uint8_t data[] = {GPIO, };
	i2c.startTransaction();
	i2c.receive(I2C_ADDRESS, sizeof(data), data);
	i2c.endTransaction();
}


/*
 * Write pins that are set as outputs
 *
 * @param: data
 */
void WritePin(unsigned data){
	uint8_t txData[] = {GPIO, data};
	i2c.startTransaction();
	i2c.transmit(I2C_ADDRESS, sizeof(txData), txData);
	i2c.endTransaction();
}
