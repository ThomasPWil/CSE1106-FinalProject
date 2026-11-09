#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17

int usertemp = 0;



int upperLimit = 76;
int lowerLimit = 68;
int size = 3;

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

void checkReadings(int upperLimit, int lowerLimit, int arr[], int size){
printf("Temperature    System Status    Warning LED");
for (int i = 0; i < size; i++){
    printf("%d F           ", arr[i]);
    if (arr[i] > 76 || arr[i] < 68){
        printf("WARNING          ");
        printf("ON\n");
    } else {
        printf("NORMAL           ");
        printf("OFF\n");
    }   
  }
}

void calculateAverage(int arr[], int size){
double sum = 0;
    for (int i = 0; i < size; i++){
    sum += arr[i];
    }
    
double average = sum / size;

printf("Average: %.2f\n", average);
    
}
