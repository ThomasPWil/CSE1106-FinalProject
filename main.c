#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17

int usertemp = 0;

int main (int argc, char* argvp[]){
    gpioInitialise();
    gpioSetMode(PIN,PI_OUTPUT);
    gpioWrite(PIN,1); //LED ON
    getchar(); // waits for Enter key
    gpioWrite(PIN,0); //LED OFF
    getchar(); //waits for Enter key
    gpioTerminate();
    
    scanf("%d", &usertemp);
    
    return 0;
}
