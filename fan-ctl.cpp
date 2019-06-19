#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
     

int main(int argc, char *argv[]) {
    
    int PIN = 0;
    int protocol = 8;
    int pulseLength = 300;

    int code = 0xE01;
    //int code = 0xFC1;

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
