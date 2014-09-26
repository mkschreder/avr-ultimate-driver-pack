#include <avr/io.h>
#include <avr/interrupt.h>

#include "time.h"

/// this holds the number of overflows of timer 1 (which counts clock ticks)
static volatile uint32_t _timer1_ovf = 0;

void time_init(){
	TCCR1A = 0; //_BV(WGM10) | _BV(WGM11); 
	TCCR1B = _BV(CS10); //_BV(WGM13) | _BV(WGM12)  | _BV(CS10); // PWM OCRA, 8 ps
	TIMSK1 |= _BV(TOIE0);
	//OCR1A = TIMER_TICKS_PER_FRAME;
}

void time_reset(){
	_timer1_ovf = 0;
	TCNT1 = 0; 
}

timeout_t time_get_clock(){
	return TCNT1 + _timer1_ovf * 65535;
}

ISR (TIMER1_OVF_vect)
{
	_timer1_ovf++;
}
