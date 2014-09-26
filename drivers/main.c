#include <stdio.h>
#include <avr/io.h>

#include <util/delay.h>

#include "dcmotor/dcmotor.h"


int main(void) {

	//init
	dcmotor_init();

	uint8_t motor0 = 0;
	uint8_t motor1 = 0;
	for(;;) {
		if(motor0 == 0)
			dcmotor_gobackward(0);
		else
			dcmotor_goforward(0);
		motor0++;
		motor0%=2;

		if(motor1 == 0)
			dcmotor_gobackward(1);
		else
			dcmotor_goforward(1);
		motor1++;
		motor1%=2;

		_delay_ms(1000);
	}
}
