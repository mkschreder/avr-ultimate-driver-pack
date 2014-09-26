#pragma once


#ifdef __cplusplus
extern "C" {
#endif

/** Macros that one should use to correctly deal with timeouts **/

typedef int32_t timeout_t;

#define time_before(unknown, known) ((timeout_t)(unknown) - (timeout_t)(known) < 0)
#define time_after(a,b) time_before(b, a)
#define timeout_from_now(us) (time_get_clock() + time_us_to_clock(us))
#define timeout_expired(timeout) (time_after(time_get_clock(), timeout))

void time_init();

// returns current number of clock cycles (will overflow!)
timeout_t time_get_clock(); 

// converts a value in microseconds to number of clock ticks
inline uint32_t time_us_to_clock(uint32_t us){
	return (F_CPU / 1000000) * us; 
}
#ifdef __cplusplus
}
#endif
