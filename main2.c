#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#include <string.h>
#include <stdbool.h>

#define PIN 17

int usertemp = 0;

void calculateAverage(int arr[], int size);

int upperLimit = 76;
int lowerLimit = 68;
int size = 3;
int tempArr[3] = {0,0,0};

FILE* fptr;


int main (int argc, char* argvp[]){
    gpioInitialise();
    gpioSetMode(PIN,PI_OUTPUT);


    for(int i = 0; i < size; i++)
    {
        printf("Enter a tempature: ");
        scanf("%d", &usertemp);
        tempArr[i] = usertemp;
    }
    
bool light = 0;
    
  printf("Temperature    System Status    Warning LED\n");
  char status[50] = "none";
  fptr = fopen("filename.txt", "w");
  if(fptr == NULL)
  {
    printf("could not open file");
    return 0;
  }
    
for (int i = 0; i < size; i++){
    printf("%d F           ", tempArr[i]);
    if (tempArr[i] > 76 || tempArr[i] < 68){
        printf("WARNING          ");
        printf("ON\n");
        light = 1;
        strcpy(status, "WARNING");
        fprintf(fptr, "%d", "%s", tempArr[i], status);
    
        
    } else {
        printf("NORMAL           ");
        strcpy(status, "NORMAL");
        printf("OFF\n");
        fprintf(fptr, "%d", "%s", tempArr[i], status);
    }
   

   
  }
if (light){
    gpioWrite(PIN,1); //LED ON
    getchar(); // waits for Enter key
}else{
    printf("Press ENTER to continue");
    getchar(); // waits for Enter key
}

    calculateAverage(tempArr, size);

    getchar(); //waits for Enter key
    gpioWrite(PIN,0); //LED OFF


    gpioTerminate();

    return 0;
}

void calculateAverage(int arr[], int size){
double sum = 0;
    for (int i = 0; i < size; i++){
    sum += arr[i];
    }
    
double average = sum / size;

printf("\n\nAverage: %.2f\n", average);
    
}
