cmake_minimum_required(VERSION 2.8)

set (CPU_FREQ "16000000UL")
set (CPU "atmega328p")
set (CPU_AVRDUDE "m328p")
#set (CPU_FREQ "18432000UL")
#set (CPU "atmega88p")
#set (CPU_AVRDUDE "m88")

set(TARGET drivers)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

include_directories("../include/avr/" "./drivers")

file(GLOB Project_SOURCES drivers/*.c)
#file(GLOB Project_SOURCES test/hello.c)
file(GLOB Project_HEADER drivers/*.h)

set (CMAKE_C_COMPILER "avr-gcc") 
set (CMAKE_C_FLAGS "-ffunction-sections -std=c99 -fdata-sections -O2 -Wl,--relax,--gc-sections -DF_CPU=${CPU_FREQ} -mmcu=${CPU}")

set (CMAKE_CXX_COMPILER "avr-g++") 
set (CMAKE_CXX_FLAGS "-ffunction-sections -fpermissive -fdata-sections -std=c++11 -O2 -Wl,--relax,--gc-sections -DF_CPU=${CPU_FREQ} -mmcu=${CPU}")

#set (CMAKE_C_COMPILER "/usr/bin/avr-gcc") 
#set (CMAKE_C_FLAGS "-ffunction-sections -fdata-sections -O2 -Wl,--relax,--gc-sections -DF_CPU=16000000UL -mmcu=atmega328p")
add_custom_target(install
    COMMAND avr-objcopy -j .text -j .data -O ihex ${TARGET} ${TARGET}.hex
    COMMAND avr-size -C -x ${TARGET}
		COMMAND sudo avrdude -p ${CPU_AVRDUDE} -c usbasp -e -U flash:w:${TARGET}.hex
    DEPENDS ${TARGET}
)

# Executable
add_library(${TARGET} ${Project_SOURCES} ${Project_HEADERS})

target_link_libraries(${TARGET})
