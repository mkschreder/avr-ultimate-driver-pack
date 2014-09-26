This is the AVR Ultimate Drivers Pack for ATMega328/ATTiny/ARDUINO.

All drivers are in C and can be compiled into a driver lib using:

	cmake . && make

I have not tested ALL of the drivers, but I have used many of them. Some drivers may need configuration on your part. But all the code is there to study and improve.

One improvement that can be done is interrupt support for all the drivers.

New drivers:
	avrbus.c - driver for my custom SPI with addressing support
	time.c - timer driver that runs timer1 at clock speed and can calculate exact delays and timeouts. 

Contributors:
	- Big thanks to Davide Geroni for writing most of the drivers in this pack.
		http://davidegironi.blogspot.se/
	- Martin K. Schröder
		info@fortmax.se
		http://oskit.se
