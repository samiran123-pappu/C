#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GOTOXY(x, y) printf("\033[%d;%df", y, x)

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
    int acct_no;
    float mobile_no;
    char street[100];
    char city[100];
    char acct_type;
    float oldbalance;
    float newbalance;
    float payment;
    struct date lastPayment;
} customer;
int tl, sl, ts;

int main(void)
{
    int i, n;
    char ch;
    system("cls");
    printf(" customer billing system : \n\n");
    printf(" ==============================\n\n");
    printf("1: ADD acount on list \n");
    printf(" 2: SEARCH for account \n");
    printf(" 3: EXIT \n\n");
    printf(" ==============================\n\n");

    do
    {
        printf("\n select what you want to do ?? \n");
        ch = getchar();
    } while (ch <= '0' || ch > '3');
    switch (ch)
    {
    case '1':
        system("cls");
        printf("\n how many customer acounts:   ");
        scanf("%d", &n);
        getchar();
        for (i = 0; i < n; i++)
        {
            input();
            if (customer.payment == 0.0)
            {
                customer.acct_type = (customer.oldbalance > 0) ? 'D' : 'C';
            }
            else
            {
                customer.acct_type = (customer.payment < customer.oldbalance) ? 'O' : 'C';
            }
            customer.newbalance = customer.oldbalance - customer.payment;
            writefile();
        }
        main();
        break;

    case '2':
        getchar();
        system("cls");
        printf("\n search by: \n 1: customer number or account number \n 2: customer name \n");
        search();
        getchar();
        main();
        break;

    case '3':
        system("cls");
        delay(500);
        GOTOXY(10, 25);
        printf(" A PROJECT BY I AM LEARNING & OTHER TUTO HHH ");
        delay(1500);
        exit(1);
    }

    return 0;
}

void input()
{
    FILE *fp;
    fp = fopen("customer.txt", "ab+");
    fseek(fp, 0, SEEK_END);
    tl = ftell(fp);
    sl = sizeof(customer);
    ts = tl / sl;
    if (ts > 0)
    {
        fseek(fp, (ts - 1) * sl, SEEK_SET);
        fread(&customer, sizeof(customer), 1, fp);
    }
    else
    {
        customer.number = 0;
    }
    printf("\ncustomer no: %d\n", ++customer.number);
    fclose(fp);
    printf(" Account number: ");
    scanf("%d", &customer.acct_no);
    getchar();
    printf("\n Name: ");
    scanf("%s", customer.name);
    getchar();
    printf("\n Mobile number: ");
    scanf("%f", &customer.mobile_no);
    getchar();
    printf("\n Street: ");
    scanf("%s", customer.street);
    getchar();
    printf("\n City: ");
    scanf("%s", customer.city);
    getchar();
    printf("\n Old balance: ");
    scanf("%f", &customer.oldbalance);
    getchar();
    printf("\n Payment: ");
    scanf("%f", &customer.payment);
    getchar();
    printf("\n Payment date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &customer.lastPayment.month, &customer.lastPayment.day, &customer.lastPayment.year);
    getchar();
}

void writefile()
{
    FILE *fp = fopen("customer.txt", "ab+");
    fwrite(&customer, sizeof(customer), 1, fp);
    fclose(fp);
    return;
}

void search()
{
    char ch;
    char nam[100];
    int n, i, m = 1;
    FILE *fp = fopen("customer.txt", "r+");

    do
    {
        printf("\n enter your choice:");
        ch = getchar();
    } while (ch != '1' && ch != '2');
    switch (ch)
    {
    case '1':
        fseek(fp, 0, SEEK_END);
        tl = ftell(fp);
        sl = sizeof(customer);
        ts = tl / sl;

        do
        {
            printf("\n enter customer number: ");
            scanf("%d", &n);
            if (n <= 0 || n > ts)
                printf("\n enter correct \n");
            else
            {
                fseek(fp, (n - 1) * sl, SEEK_SET);
                fread(&customer, sizeof(customer), 1, fp);
                output();
            }
            printf("\n\n again ? (y/n)");
            scanf(" %c", &ch);
        } while (ch == 'y');
        fclose(fp);
        break;

    case '2':
        fseek(fp, 0, SEEK_END);
        tl = ftell(fp);
        sl = sizeof(customer);
        ts = tl / sl;
        fseek(fp, (ts - 1) * sl, SEEK_SET);
        fread(&customer, sl, 1, fp);
        n = customer.number;

        do
        {
            printf("\n enter customer name: ");
            scanf("%s", nam);
            fseek(fp, 0, SEEK_SET);
            for (i = 1; i <= n; i++)
            {
                fread(&customer, sl, 1, fp);

                if (strcmp(customer.name, nam) == 0)
                {
                    output();
                    m = 0;
                    break;
                }
            }
            if (m != 0)
                printf("\n record not found \n");
            printf("\n\n again ? (y/n)");
            scanf(" %c", &ch);
        } while (ch == 'y');
        fclose(fp);
    }
    return;
}
void output()
{
    printf("\n Customer no: %d\n", customer.number);
    printf(" Name: %s\n", customer.name);
    printf(" Account no: %d\n", customer.acct_no);
    printf(" Mobile no: %.0f\n", customer.mobile_no);
    printf(" Street: %s\n", customer.street);
    printf(" City: %s\n", customer.city);
    printf(" Old balance: %.2f\n", customer.oldbalance);
    printf(" Payment: %.2f\n", customer.payment);
    printf(" New balance: %.2f\n", customer.newbalance);
    printf(" Payment date: %d/%d/%d\n", customer.lastPayment.month, customer.lastPayment.day, customer.lastPayment.year);
    printf("                  Account Status:");

    switch (customer.acct_type)
    {
    case 'O':
        printf(" Overdue\n\n");
        break;
    case 'D':
        printf(" Delinquent\n\n");
        break;
    case 'C':
        printf(" Current\n\n");
        break;
    default:
        printf(" ERROR\n\n");
    }
    return;
}
