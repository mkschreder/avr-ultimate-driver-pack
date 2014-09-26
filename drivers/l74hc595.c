/*
l74hc595 lib 0x01

copyright (c) Davide Gironi, 2011

References: bildr 74hc595 library for arduino
	http://bildr.org/2011/08/74hc595-breakout-arduino/

Released under GPLv3.
Please refer to LICENSE file for licensing information.
*/


#include <stdio.h>
#include <avr/io.h>

#include "l74hc595.h"

/*
 * set a register on or off
 */
void l74hc595_setreg(uint16_t regindex, uint8_t val) {
	//get valid byteindex, first byte is for first ic attached
	uint16_t byteindex = (L74HC595_ICNUMBER-1)-regindex/8;
	//bit address 0 is Qa
	uint8_t bitindex = (8-1) - regindex % 8;

	uint8_t current = l74hc595_icarray[byteindex];

	current &= ~(1 << bitindex); //clear the bit
	current |= val << bitindex; //set the bit

	l74hc595_icarray[byteindex] = current; //set the new value
}

/*
 * set all ports of a chip
 */
void l74hc595_setchipbyte(uint8_t chipindex, uint8_t val) {
	l74hc595_icarray[L74HC595_ICNUMBER-1-chipindex] = val; //set the new value
}

/*
 * set all registers off
 */
void l74hc595_setregalloff() {
	for(uint16_t i = 0; i < L74HC595_ICNUMBER*8; i++){
		l74hc595_setreg(i, 0);
	}
}

/*
 * set all registers on
 */
void l74hc595_setregallon() {
	for(uint16_t i = 0; i < L74HC595_ICNUMBER*8; i++){
		l74hc595_setreg(i, 1);
	}
}

/*
 * init the shift register
 */
void l74hc595_init() {
	//output
	L74HC595_DDR |= (1 << L74HC595_SERPIN);
	L74HC595_DDR |= (1 << L74HC595_RCLKPIN);
	L74HC595_DDR |= (1 << L74HC595_SRCLKPIN);
	//low
	L74HC595_PORT &= ~(1 << L74HC595_SERPIN);
	L74HC595_PORT &= ~(1 << L74HC595_RCLKPIN);
	L74HC595_PORT &= ~(1 << L74HC595_SRCLKPIN);
	//init registers
	l74hc595_setregalloff();
}

/*
 * shift out data
 */
void l74hc595_shiftout() {
	L74HC595_PORT &= ~(1 << L74HC595_RCLKPIN); //set the register-clock pin low
	for(uint8_t i = 0; i < L74HC595_ICNUMBER; i++){
		//iterate through the bits in each registers
		for(uint8_t j = 0; j < 8; j++){
			L74HC595_PORT &= ~(1 << L74HC595_SRCLKPIN); //set the serial-clock pin low
			uint8_t val = (l74hc595_icarray[i] & (1 << j))>>j;
			L74HC595_PORT |= (val << L74HC595_SERPIN);
			L74HC595_PORT |= (1 << L74HC595_SRCLKPIN); //set the serial-clock pin high
			L74HC595_PORT &= ~(val << L74HC595_SERPIN); //set the datapin low again
		}
	}
	L74HC595_PORT |= (1 << L74HC595_RCLKPIN); //set the register-clock pin high to update the output of the shift-register
}
