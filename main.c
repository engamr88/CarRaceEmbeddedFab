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
int moveRight(int *ptr);
void moveLeft(int *ptr);
void initCar(char (*arr)[carWidth]);
unsigned int rand_interval(unsigned int , unsigned int );
void delay(int milliseconds);
int main()
{

    //  int key = 0;
    int mainCarRowPos=screenHeight-3;
    int car1rowPos=0;
    int car2rowPos=0;
    int car1colPos=1;
    int car2colPos=screenWidth-4;
    while(1)
    {
        char LCD[screenHeight][screenWidth]; //LCD main memory array
        char Car[carHeight][carWidth];
        char car1[carHeight][carWidth];
        char car2[carHeight][carWidth];
        initCar(Car);
        initCar(car1);
        initCar(car2);
        screenArea(LCD);
        drawCar(LCD,Car,mainCarRowPos,screenWidth/2);
        drawCar(LCD,car1,car1rowPos,car1colPos);
        drawCar(LCD,car2,car2rowPos,car2colPos);
        if(car1rowPos!=screenHeight-1)
        {
            car1rowPos++;
            car2rowPos++;
        }
        else
        {
            car1colPos =rand_interval(1,screenWidth-4);
            fflush(stdin);
            car2colPos =rand_interval(1,screenWidth-4);
            fflush(stdin);

            car1rowPos=0;
            car2rowPos=0;
        }


        clearScreen();
        printScreen(LCD);
        //delay(150);
        /* if(moveRight(&key)==0)
          break;

         printf("%d",moveRight(&key));*/
        fflush(stdin);
    }
    return 0;
}
void initCar(char (*arr)[carWidth])
{
    arr[0][0]='*';
    arr[0][1]=' ';
    arr[0][2]='*';

    arr[1][0]=' ';
    arr[1][1]='*';
    arr[1][2]=' ';

    arr[2][0]='*';
    arr[2][1]=' ';
    arr[2][2]='*';
}
/////////////////////////////////////

void screenArea(char (*arr)[screenWidth])
{
    int i=0,j=0;
    for(i = 0; i < screenHeight ; i++)
    {
        for(j = 0; j < screenWidth ; j++)
        {
            if(j==0||j==screenWidth-1)
            {
                arr[i][j] = '*';
            }
            else
            {
                arr[i][j] = ' ';
            }
        }
    }
//printScreen(arr);
}

void printScreen(char (*arr)[screenWidth])
{

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
void clearScreen()
{
    system("cls");
}

void drawCar(char (*source)[screenWidth],char (*target)[carWidth],int posRow,int posCol)
{
    int i=0,j=0;
    for(i = 0; i < screenHeight ; i++)
    {
        for(j = 0; j < screenWidth ; j++)
        {

            if(i<carHeight&&j<carWidth)
            {
                source[i+posRow][j+posCol]=target[i][j];
            }

        }
    }
}

int moveRight(int *key)
{
    if (kbhit())
    {
        *(key) =getch();
//printf("%d",*(key));
        if (*(key) == 'M')
            return 0;
    }
    return 1;
}

unsigned int rand_interval(unsigned int min, unsigned int max)
{

    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    }
    while (r >= limit);

    return min + (r / buckets);
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
