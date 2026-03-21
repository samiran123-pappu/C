#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct date
{
    int month, day, year;
};

struct
{
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add, upd, check, rem, transaction;

int main_exit;

void menu();
void new_acc();
void edit();
void transact();
void see();
void erase();
void view_list();
void close_app();
void fordelay(int j);

int main()
{
    char pass[15], password[15] =
                       "iamlearning";

    int i = 0;
    printf("\n\n\t\tEnter the password to login:");

    scanf("%s", pass);
    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword match! Loading... ");
        fordelay(5);
        menu();
    }
    else
    {
        printf("\n\nWrong Password!!!");
        exit(0);
    }
    return 0;
}

void menu()
{
    int choice;
    system("cls");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1.Create new account\n\n\t\t2.Update information of existing account\n\t\t3.For transaction\n\n\t\t4.Check the details of existing account\n\n\t5.Remove existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close_app();
        break;
    default:
        printf("\nInvalid choice! Please try again.\n");
        menu();
        break;
    }
}

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr = fopen("record.dat", "a+");
    if (ptr == NULL)
    {
        printf("\nUnable to open record file!");
        return;
    }
account_no:
    rewind(ptr);
    system("cls");
    printf("\t\t\t\t ADD RECORD ");
    printf("\n\n\n Enter today's date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\nEnter the account number: ");
    scanf("%d", &check.acc_no);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no, already in use!");
            fordelay(2);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter the name of the account holder: ");
    scanf("%s", add.name);
    printf("\nEnter the date of birth (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    printf("\nEnter the address: ");
    scanf("%s", add.address);
    printf("\nEnter the citizenship: ");
    scanf("%s", add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);

    printf("\nEnter the amount to deposit: ");
    scanf("%f", &add.amt);

    printf("\nEnter the type of account (saving/current/fixed1/fixed2/fixed3): ");
    scanf("%s", add.acc_type);

    fseek(ptr, 0, SEEK_END);
    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    fclose(ptr);
    printf("\nAccount created successfully!");

add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close_app();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void edit()
{
    int choice, test = 0;
    FILE *old, *newrec;

    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    if (old == NULL || newrec == NULL)
    {
        printf("\nUnable to open record file!");
        if (old != NULL)
            fclose(old);
        if (newrec != NULL)
            fclose(newrec);
        return;
    }

    printf("Enter the account number of the customer you want to edit: ");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address, 2 for phone): ");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the new address: ");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number: ");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("Changes saved!");
            }
            else
            {
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
        printf("\nRecord not found!!");
edit_invalid:
    printf("\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close_app();
    else if (main_exit == 0)
        edit();
    else
    {
        printf("\nInvalid!\a");
        goto edit_invalid;
    }
}

void transact()
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    if (old == NULL || newrec == NULL)
    {
        printf("\nUnable to open record file!");
        if (old != NULL)
            fclose(old);
        if (newrec != NULL)
            fclose(newrec);
        return;
    }

    printf("\nEnter the account no. of the customer: ");
    scanf("%d", &transaction.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw\n\nEnter your choice(1 for deposit and 2 for withdraw): ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit: $");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else if (choice == 2)
            {
                printf("Enter the amount you want to withdraw: $");
                scanf("%f", &transaction.amt);
                if (transaction.amt <= add.amt)
                {
                    add.amt -= transaction.amt;
                    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }
                else
                {
                    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                    printf("\n\nInsufficient balance!");
                }
            }
            else
            {
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nInvalid transaction choice!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
        printf("\nRecord not found!!");

transact_invalid:
    printf("\n\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close_app();
    else if (main_exit == 0)
        transact();
    else
    {
        printf("\nInvalid!\a");
        goto transact_invalid;
    }
}

void see()
{
    FILE *ptr;
    int test = 0, choice;
    ptr = fopen("record.dat", "r");
    if (ptr == NULL)
    {
        printf("\nUnable to open record file!");
        return;
    }
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice: ");

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter the account number: ");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;
                printf("\nAccount NO.:%d\nName:%s\nDOB:%d/%d/%d\nAge:%d\nAddress:%s\nCitizenship No:%s\nPhone number:%.0lf\nType Of Account:%s\nAmount deposited:%.2f\nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name: ");
        scanf("%s", check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmp(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\nAccount NO.:%d\nName:%s\nDOB:%d/%d/%d\nAge:%d\nAddress:%s\nCitizenship No:%s\nPhone number:%.0lf\nType Of Account:%s\nAmount deposited:%.2f\nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
            }
        }
    }
    else
    {
        printf("\nInvalid choice!");
        test = -1;
    }

    fclose(ptr);
    if (test == 0)
        printf("\nRecord not found!!");

see_invalid:
    printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close_app();
    else if (main_exit == 0)
        see();
    else
    {
        printf("\nInvalid!\a");
        goto see_invalid;
    }
}

void erase()
{
    FILE *old, *newrec;
    int test = 0;

    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    if (old == NULL || newrec == NULL)
    {
        printf("\nUnable to open record file!");
        if (old != NULL)
            fclose(old);
        if (newrec != NULL)
            fclose(newrec);
        return;
    }
    printf("Enter the account no. of the customer you want to delete: ");
    scanf("%d", &rem.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
        else
        {
            test++;
            printf("\nRecord deleted successfully!");
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test == 0)
        printf("\nRecord not found!!");
erase_invalid:
    printf("\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        close_app();
    else if (main_exit == 0)
        erase();
    else
    {
        printf("\nInvalid!\a");
        goto erase_invalid;
    }
}


void view_list(){
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    if (view == NULL) {
        printf("\nUnable to open record file!");
        return;
    }
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF) {
        printf("%d\t\t%s\t\t%s\t\t%.0lf\n", add.acc_no, add.name, add.address, add.phone);
        test = 1;
    }

    fclose(view);
    if (test == 0) {
        printf("\nNo records found!");
    }

    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d", &main_exit);
    if (main_exit == 1) {
        menu();
    } else if (main_exit == 0) {
        close_app();
    } else {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}

void close_app()
{
    printf("\n\n\nThank you for using the Customer Account Banking Management System!\n");
    exit(0);
}

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

