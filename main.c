#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17

int usertemp = 0;

void checkReadings(int upperLimit, int lowerLimit, int arr[], int size);
void calculateAverage(int arr[], int size);

int upperLimit = 76;
int lowerLimit = 68;
int size = 3;
int tempArr[3] = {0,0,0};

int main (int argc, char* argvp[]){
    gpioInitialise();
    gpioSetMode(PIN,PI_OUTPUT);
    gpioWrite(PIN,1); //LED ON
    getchar(); // waits for Enter key
    gpioWrite(PIN,0); //LED OFF
    getchar(); //waits for Enter key
    gpioTerminate();
    
    for(int i = 0; i < size; i++)
    {
        printf("Enter a tempature: ");
        scanf("%d", &usertemp);
        tempArr[i] = usertemp;
    }
    
    return 0;
}

void checkReadings(int upperLimit, int lowerLimit, int arr[], int size){

bool light = 0;
    
printf("Temperature    System Status    Warning LED\n");
for (int i = 0; i < size; i++){
    printf("%d F           ", arr[i]);
    if (arr[i] > 76 || arr[i] < 68){
        printf("WARNING          ");
        printf("ON\n");
        bool light = 1;
    } else {
        printf("NORMAL           ");
        printf("OFF\n");
    }   
  }
if (light){
    gpioWrite(PIN,1); //LED ON
    getchar(); // waits for Enter key
} else{
    gpioWrite(PIN,0); //LED OFF
    getchar(); //waits for Enter key
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
