#include "kernel.h"

extern void app_init(void); 
extern void app_loop(void); 

int main(){
	app_init(); 
	
	while(1){
		app_loop(); 
		
		#ifdef RFNET
		rfnet_process_events(); 
		#endif
		
		#ifdef TCPIP
		ip_process_packets(); 
		#endif
	}
}
