#pragma once

#include <avr/io.h>
#include "crypto/aes/aes.h"
#include "stack.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char rfnet_mac_t[5]; 
typedef unsigned char rfnet_key_t[32]; 
typedef unsigned char rfnet_pw_t[13]; 

typedef int8_t 		rfnet_handle_t; 

#define RFNET_INVALID_HANDLE -1

#define RFNET_PACKET_DATA_SIZE 21

typedef enum {
	RFNET_ERR_UNDEFINED = 0, 
	RFNET_ERR_READ_REQ_SEND_FAIL = -1, 
	RFNET_ERR_TIMEOUT 					 = -2, 
	RFNET_ERR_INVALID_MESSAGE 	 = -3, 
	RFNET_ERR_BUFFER_SEND_FAILED = -4,
	RFNET_ERR_NONCE_MISMATCH 		 = -5,
	RFNET_ERR_INVALID_PACKET		 = -6,
	RFNET_ERR_CONNECT_TIMEOUT 	 = -7,
} rfnet_error_t; 

typedef uint8_t (*rfnet_request_handler_proc_t)(
	const uint8_t *indata, 
	uint8_t insize, 
	uint8_t *outdata, 
	uint8_t outsize); 
typedef uint8_t (*rfnet_response_handler_proc_t)(
	const uint8_t *data, 
	uint8_t size); 
typedef void (*rfnet_error_proc_t)(rfnet_error_t err, const char *desc); 

void rfnet_init(rfnet_mac_t addr, const char *root_pw, 
	volatile uint8_t *outport, volatile uint8_t *ddrport, 
	uint8_t cepin, uint8_t cspin, 
	rfnet_request_handler_proc_t data_proc, 
	rfnet_response_handler_proc_t cb_resp, 
	rfnet_error_proc_t error_proc); 
	
uint8_t rfnet_send(uint8_t *data, uint8_t size); 
uint8_t rfnet_connect(rfnet_mac_t addr, const char *pw, 
	rfnet_response_handler_proc_t data_ready); 
void rfnet_process_events(void); 
uint8_t rfnet_is_busy(void); 


#ifdef __cplusplus
}
#endif
