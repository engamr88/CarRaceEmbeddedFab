#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
// preprocessors
#define screenWidth 100
#define screenHeight 20
#define carWidth 3
#define carHeight 3

// protoTypes
 void screenArea(char (*arr)[screenWidth]);
 void printScreen(char (*arr)[screenWidth]);
 void clearScreen(void);
 void drawCar(char (*source)[screenWidth],char (*target)[carWidth],int ,int );
 void waitFor (unsigned int);
 int moveRight(int *ptr);
 void moveLeft(int *ptr);

int main()
{

     int key = 0;
    int mainCarRowPos=screenHeight-3;
    while(1){
    char LCD[screenHeight][screenWidth]; //LCD main memory array
    char Car[carHeight][carWidth] = {{'*',' ','*'},{' ','*',' '},{'*',' ','*'}};//Car object
    screenArea(LCD);
    drawCar(LCD,Car,mainCarRowPos,screenWidth/2);
    mainCarRowPos--;
     waitFor(1);
 clearScreen();
    printScreen(LCD);

  /* if(moveRight(&key)==0)
    break;
*/
   printf("%d",moveRight(&key));

}
return 0;
}
/////////////////////////////////////
void waitFor (unsigned int secs) {
int retTime = time(0) + secs;     // Get finishing time.
    while (time(0) < retTime);    // Loop until it arrives.
}
 void screenArea(char (*arr)[screenWidth]){
    int i=0,j=0;
   for(i = 0; i < screenHeight ; i++)
   {
       	for(j = 0; j < screenWidth ; j++)
		{
		    if(j==0||j==screenWidth-1){
              arr[i][j] = '*';
		    }else{
		    	arr[i][j] = ' ';
		    }
		}
   }
//printScreen(arr);
}

void printScreen(char (*arr)[screenWidth]){

    int i=0,j=0;
 for(i = 0; i < screenHeight ; i++)
   {
       	for(j = 0; j < screenWidth ; j++)
		{
		//    printf("height:: %d,Width::  %d",i,j);
		    printf("%c",arr[i][j]);
		}
		printf("\n");
   }
}
void clearScreen(){
 system("cls");
}

void drawCar(char (*source)[screenWidth],char (*target)[carWidth],int posRow,int posCol){
    int i=0,j=0;
 for(i = 0; i < screenHeight ; i++)
   {
       	for(j = 0; j < screenWidth ; j++)
		{

		    if(i<carHeight&&j<carWidth){
                 source[i+posRow][j+posCol]=target[i][j];
		    }

        }
    }
}

int moveRight(int *key){
 if (kbhit())
    {
      *(key) =getch();
//printf("%d",*(key));
     if (*(key) == 'M')
        return 0;
    }
     return 1;
}

