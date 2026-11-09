#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#include <string.h>

#define PIN 17

int usertemp = 0;

void checkReadings(int upperLimit, int lowerLimit, int arr[], int size);
void calculateAverage(int arr[], int size);

int upperLimit = 76;
int lowerLimit = 68;
int size = 3;
int tempArr[3] = {0,0,0};

FILE* fptr;


int main (int argc, char* argvp[]){
    gpioInitialise();
    
    for(int i = 0; i < size; i++)
    {
        printf("Enter a tempature: ");
        scanf("%d", &usertemp);
        tempArr[i] = usertemp;
    }

    checkReadings(upperLimit, lowerLimit, tempArr, size);

    calculateAverage(tempArr, size);

    gpioTerminate();
    
    return 0;
}

void checkReadings(int upperLimit, int lowerLimit, int arr[], int size){
printf("Temperature    System Status    Warning LED\n");
char status[50] = "none";

for (int i = 0; i < size; i++){
    printf("%d F           ", arr[i]);
    if (arr[i] > 76 || arr[i] < 68){
        printf("WARNING          ");
        printf("ON\n");
        
        strcpy(status, "WARNING");
        if(fptr == NULL)
         {
          printf("could not open file");
          return;
        }
        fptr = fopen("filename.txt", "w");
        fprintf(fptr, "%d", "%s", arr[i], status);
    
        
    } else {
        printf("NORMAL           ");
        strcpy(status, "NORMAL");
        printf("OFF\n");
        
        fptr = fopen("filename.txt", "w");
         if(fptr == NULL)
         {
          printf("could not open file");
          return;
        }
        fprintf(fptr, "%d", "%s", arr[i], status);
    }
   

    // Write some text to the file
   
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
