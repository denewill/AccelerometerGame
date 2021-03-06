/*
 * mcpio.h
 *
 * MCP23008 I/O port expander header file
 */
#ifndef SOURCES_MCPIO_H_
#define SOURCES_MCPIO_H_

//register addresses from MCP23008 data sheet
enum RegisterAddress{
	IODIR 	= 0x00,
	IPOL  	= 0x01,
	GPINTEN	= 0x02,
	DEFVAL	= 0x03,
	INTCON	= 0x04,
	IOCON	= 0x05,
	GPPU	= 0x06,
	INTF	= 0x07,
	INTCAP 	= 0x08,
	GPIO	= 0x09,
	OLAT	= 0x0A
};

/*
 * Set the direction of the individual bits of the port
 * input => direction = 1
 * output => direction = 0
 *
 * @param[in]: direction
 */
void SetDirection(unsigned direction);

/*
 * Set direction as input
 *
 * @param:-
 */
void SetInput();

/*
 * Set direction as output
 *
 * @param:-
 */
void SetOutput();

/*
 * Read pins that are set as inputs
 *
 * @param:-
 */
void ReadPin();

/*
 * Write pins that are set as outputs
 *
 * @param[in]: data
 */
void WritePin(unsigned data);

#endif /* SOURCES_MCPIO_H_ */
