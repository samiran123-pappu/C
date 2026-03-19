/* c program to design a digital clock  */

#include<stdio.h>
#include<time.h> // for sleep () function
#include<unistd.h>
#include<stdlib.h>

int main ()
{
    int hour, minute, second;
    hour = minute = second = 0;
    while(1)
{
// clear output screen
system("cls");
// print time in the format of HH:MM:SS
printf("%02d : %02d : %02d", hour, minute, second);
// clear output buffer in gcc
fflush(stdout);
// increse second
second++ ;
// update hour, minute, second
if (second == 60){
    second = 0;
    minute++;
}
if( minute == 60){
    hour +=1;
    minute = 0;
}
if(hour == 24){
    hour = 0;
    minute = 0;
    second = 0;
}
sleep(1);  // wait till 1 second
}
return 0;
}
