#pragma once 

#include "kconfig.h"
#include "kdepends.h"

#include <inttypes.h>

#include "random.h"
#include "time.h"

//#include "accel_docalibration.h"

#ifdef ACS712
#include "acs712.h"
#endif

#ifdef ADC
#include "adc.h"
#endif

#ifdef ADXL345
#include "adxl345.h"
#endif

#ifdef ATM1001
#include "amt1001.h"
#endif

//#include "audioget.h"
#ifdef AVRBUS
#include "avrbus.h"
#endif

#ifdef BH1750
#include "bh1750.h"
#endif

//#include "bldcsensored.h"
//#include "bldcsensorless.h"

#ifdef BMP085
#include "bmp085.h"
#endif

//#include "dcmotor.h"
//#include "dcmotorpwm.h"
//#include "dcmotorpwmsoft.h"

#ifdef DHT11
#include "dht.h"
#endif

#ifdef DS18B20
#include "ds18b20.h"
#endif

#ifdef ENC28J60
#include "enc28j60.h"
#endif

#ifdef FFT
#include "fftradix4.h"
#endif

#ifdef FS300A
#include "fs300a.h"
#endif

//#include "gyro_docalibration.h"
#ifdef HCSR04
#include "hcsr04.h"
#endif

#ifdef HMC5883L
#include "hmc5883l.h"
#endif

#ifdef I2CMASTER
#include "i2cmaster.h"
#endif

#ifdef I2CSLAVE
#include "twi_slave.h"
#endif

//#include "i2csoft.h"
//#include "i2csw.h"
//#include "i2csw_slave.h"

#ifdef ILI9340
#include "ili9340.h"
#endif

#ifdef IMU10DOF01
#include "imu10dof01.h"
#endif

#ifdef L3G4200D
#include "l3g4200d.h"
#endif

#ifdef L74HC165
#include "l74hc165.h"
#endif

#ifdef L74HC4051
#include "l74hc4051.h"
#endif

#ifdef L74HC595
#include "l74hc595.h"
#endif

//#include "lcdpcf8574.h"
//#include "ldr.h"
//#include "ledmatrix88.h"
//#include "magn_docalibration.h"
#ifdef MFRC522
#include "mfrc522.h"
#endif

#ifdef MMA7455
#include "mma7455.h"
#endif

#ifdef MPU6050
#include "mpu6050.h"
#include "mpu6050registers.h"
#endif

#ifdef NRF24L01
#include "nrf24l01.h"
#include "nrf24l01registers.h"
#endif

//#include "ntctemp.h"
#ifdef PCF8574
#include "pcf8574.h"
#endif

//#include "pwm.h"
//#include "pwmcd4017.h"
//#include "pwmcd4017servo.h"
#ifdef RFNET
#include "rfnet.h"
#endif

//#include "sevseg.h"
//#include "softi2c.h"
#ifdef SPI
#include "spi.h"
#endif

#ifdef SSD1306
#include "ssd1306.h"
#include "ssd1306_priv.h"
#endif

//#include "stepper02.h"
//#include "stepper04multi.h"
#if defined(TCPIP) | defined(TCP) | defined(UDP)
#include "tcpip.h"
#endif

//#include "temt6000.h"
//#include "tsl235.h"
#ifdef UART
#include "uart.h"
#endif

#ifdef VT100
#include "vt100.h"
#endif

//#include "wiinunchuck.h"
