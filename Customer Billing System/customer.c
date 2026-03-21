#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GOTOXY(X, Y) printf("\033[%d;%dH", Y, X)

void delay(int time)
{
    int milli = 1000 * time;
    clock();
    while (clock() < milli)
        ;
}

void input();
void writefile();
void search();
void output();

struct date
{
    int month;
    int day;
    int year;
};

struct account
{
    int number;
    char name[100];
    int acc_no;
    float mobile_no;
    char street[100];
    char city[100];
    char acc_type;
    float oldbalance;
    float newbalance;
    float payment;
    struct date lastPayment;
} customer;
int tl, sl, ts;

int main()
{
    int i, n;
    char ch;
    while (1)
    {
        system("cls");
        printf(" customer billing system : \n\n");
        printf(" ==============================\n\n");
        printf("1: ADD acount on list \n");
        printf(" 2: SEARCH for account \n");
        printf(" 3: EXIT \n\n");
        printf(" ==============================\n\n");

        do
        {
            printf("\n select what oyu want to do ?? \n");
            ch = getchar();
        } while (ch <= '0' || ch > '3');
        getchar();

        switch(ch){
            case '1':
            system("cls");
            printf("\n how many customer acounts:   ");
            scanf("%d", &n);
            getchar();
            for(i=0; i<n; i++){
                input();
                if(customer.payment > 0.0)
                customer.acc_type = (customer.payment < customer.oldbalance) ? 'O' : 'D';
                else
                customer.acc_type = (customer.oldbalance > 0.0) ? 'D' : 'C';
                customer.newbalance = customer.oldbalance - customer.payment;
                writefile();
            }
            break;

            case '2':
            system("cls");
            printf("search by what ?? \n\n");
            printf("1:---------------search by customer number \n");
            printf("2:---------------search by customer name \n");
            search();
            break;

            case '3':
            system("cls");
            delay(500);
            GOTOXY(10, 25);
            printf(" A PROJECT BY I AM LEARNING & OTHER TUTO HHH");
            delay(1500);
            return 0;
        }
    }
}


void input(){
    FILE *fp;
    fp = fopen("customer.txt", "ab+");
    if(fp == NULL){
        printf("\n unable to open customer file.\n");
        return;
    }
    fseek(fp, 0, SEEK_END);
    tl = ftell(fp);
    sl = sizeof(customer);
    ts = tl / sl;
    if(ts > 0){
        fseek(fp, (ts-1)*sl, SEEK_SET);
        fread(&customer, sizeof(customer), 1, fp);
    }
    else{
        customer.number = 0;
    }
    printf("\ncustomer no: %d\n", ++customer.number);
    fclose(fp);
    printf(" customer name:  ");
    scanf("%s", customer.name);
    getchar();
    printf(" Acount Number:  ");
    scanf("%d", &customer.acc_no);
    getchar();
    printf("\n customer mobile no:  ");
    scanf("%f", &customer.mobile_no);
    getchar();
    printf(" customer street:  ");
    scanf("%s", customer.street);
    getchar();
    printf(" customer city:  ");
    scanf("%s", customer.city);
    getchar();
    printf(" customer old balance:  ");
    scanf("%f", &customer.oldbalance);
    getchar();
    printf(" customer payment:  ");
    scanf("%f", &customer.payment);
    getchar();
    printf(" payment date (mm/dd/yyyy):  ");
    scanf("%d/%d/%d", &customer.lastPayment.month, &customer.lastPayment.day, &customer.lastPayment.year);
    getchar();
}



void writefile(){
    FILE *fp;
    fp = fopen("customer.txt", "ab+");
    if(fp == NULL){
        printf("\n unable to open customer file.\n");
        return;
    }
    fwrite(&customer, sizeof(customer), 1, fp);
    fclose(fp);
    return;
}

void search(){
    FILE *fp;
    int choice;
    int number;
    int found = 0;
    char name[100];

    fp = fopen("customer.txt", "rb");
    if(fp == NULL){
        printf("\n unable to open customer file or no customer records found.\n");
        return;
    }

    printf("\n enter your choice: ");
    scanf("%d", &choice);
    getchar();

    if(choice == 1){
        printf(" enter customer number: ");
        scanf("%d", &number);
        getchar();

        while(fread(&customer, sizeof(customer), 1, fp) == 1){
            if(customer.number == number || customer.acc_no == number){
                found = 1;
                printf("\n customer no: %d\n", customer.number);
                printf(" account no: %d\n", customer.acc_no);
                printf(" mobile no: %.0f\n", customer.mobile_no);
                printf(" street: %s\n", customer.street);
                printf(" city: %s\n", customer.city);
                printf(" old balance: %.2f\n", customer.oldbalance);
                printf(" payment: %.2f\n", customer.payment);
                printf(" new balance: %.2f\n", customer.newbalance);
                printf(" payment date: %d/%d/%d\n", customer.lastPayment.month, customer.lastPayment.day, customer.lastPayment.year);
                break;
            }
        }
    }
    else if(choice == 2){
        printf(" enter customer name: ");
        scanf("%s", name);
        getchar();

        while(fread(&customer, sizeof(customer), 1, fp) == 1){
            if(strcmp(customer.name, name) == 0){
                found = 1;
                printf("\n customer no: %d\n", customer.number);
                printf(" account no: %d\n", customer.acc_no);
                printf(" mobile no: %.0f\n", customer.mobile_no);
                printf(" street: %s\n", customer.street);
                printf(" city: %s\n", customer.city);
                printf(" old balance: %.2f\n", customer.oldbalance);
                printf(" payment: %.2f\n", customer.payment);
                printf(" new balance: %.2f\n", customer.newbalance);
                printf(" payment date: %d/%d/%d\n", customer.lastPayment.month, customer.lastPayment.day, customer.lastPayment.year);
                break;
            }
        }
    }
    else{
        printf("\n invalid choice.\n");
    }

    if(!found && (choice == 1 || choice == 2)){
        printf("\n record not found.\n");
    }

    fclose(fp);
}




void output(){
    printf("\n Customer no: %d\n", customer.number);
    printf(" Name: %s\n", customer.name);
    printf(" Account no: %d\n", customer.acc_no);
    printf(" Mobile no: %.0f\n", customer.mobile_no);
    printf(" Street: %s\n", customer.street);
    printf(" City: %s\n", customer.city);
    printf(" Old balance: %.2f\n", customer.oldbalance);
    printf(" Payment: %.2f\n", customer.payment);
    printf(" New balance: %.2f\n", customer.newbalance);
    printf(" Payment date: %d/%d/%d\n", customer.lastPayment.month, customer.lastPayment.day, customer.lastPayment.year);

    switch (customer.acc_type)
    {
    case 'C':
        printf("CURRENT \n\n");
        break;

    case 'O':
        printf("OVERDUE \n\n");
        break;

    case 'D':
        printf("DUE \n\n");
        break;
    
    default:
        printf("UNKNOWN \n\n");
        break;
    }
    return;


}