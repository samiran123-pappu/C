// calender in c
#include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = 
{
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

int inputyear(void)
{
    int year;
    printf("please enter the year: ");
    scanf("%d", &year);
    return year;
}

int determineleapyear(int year)
{
    if((year % 4 == FALSE && year % 100 != FALSE) || (year % 400 == FALSE)){
        days_in_month[2] = 29;
        return TRUE;
    }
    else{
        days_in_month[2] = 28;
        return FALSE;
    
    }
     
}


int determinedaycode(int year){
    int daycode;

    int d1, d2, d3;

    d1 = (year - 1) / 4.0;
    d2 = (year - 1) / 100.0;
    d3 = (year - 1) / 400.0;

    daycode = (year + d1 - d2 + d3) % 7;

    return daycode;
}

void calender(int year, int daycode)
{
    int month, day;

    for(month = 1; month <= 12; month++){
        printf("%s", months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // correct the position of the first day in the month
        for(day = 1; day <= 1 + daycode * 5; day++){
            printf(" ");
        }

        // print all the days in the month
        for(day = 1; day <= days_in_month[month]; day++){
            printf("%2d ", day);

            // is day before sat ? if not, print a new line
            if((day + daycode) % 7 >0)
                printf(" ");
            else
                printf("\n");
            
            // set position for the next month
        }
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main (void)
{
    int year, daycode, leapyear;
    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calender(year, daycode);
    printf("\n");
}
