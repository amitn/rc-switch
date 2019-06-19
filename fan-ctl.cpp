#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>


//00_0001 - Light On/Off			1
//00_0010 - On/Off				2
//00_0100 - Turn				4
//
//00_1000 - Speed x-2				8
//00_1010 - Speed x-1			   	10		
//01_0000 - Speed X			  	16
//01_1000 - Speed X+1				24
//10_0010 - Speed X+2				34	
//10_0000 - Speed X+3				32
     

int main(int argc, char *argv[]) {
    
    int PIN = 0;
    int protocol = 8;
    int pulseLength = 300;

    int code = 0xFC1;
    int addr = 0x3F; // 0x38
    if (argc >= 2) {
	    addr = atoi(argv[1]);
    }
    code = addr << 6;

    if (argc >= 3) {
	    // function
	    code |= atoi(argv[2]);
    } else {
	   code |= 1;
    }


    if (wiringPiSetup () == -1) return 1;
    RCSwitch mySwitch = RCSwitch();
    mySwitch.setProtocol(protocol);
    mySwitch.setPulseLength(pulseLength);
    mySwitch.setRepeatTransmit(9);
    mySwitch.enableTransmit(PIN);
    
	//mySwitch.sendRepeat(code, 12, 3);
    mySwitch.send(code, 12);
    
    return 0;

}
