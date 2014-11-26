#pragma once

#ifdef I2C
	#undef I2CMASTER
	#undef I2CSLAVE
	#define I2CMASTER
	#define I2CSLAVE
#endif

#ifdef RFNET
	#undef NRF24L01
	#undef TIME
	#define NRF24L01
	#define TIME
#endif

#ifdef BLDCSENSORLESS
	#ifdef PWMCD4017
	#error "BLDCSENSORLESS is incompatible with PWMCD4017!"
	#endif
#endif

