#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menu()
{
    printf("\n1-------------------------->storing\n");
    printf("2----------------------------------->display\n");
    printf("3-------------------------->number of words to display\n");
    printf("4-------------------------->reverse\n");
    printf("0-------------------------->exit\n");
    printf("\nenter your choice : ");
    return (getchar());
}

char *storing()
{
    char array[80];
    char *type = NULL;
    printf("\ntype : ");
    fgets(array, 80, stdin);
    type = (char *)malloc(strlen(array) + 1);
    strcpy(type, array);
    return type;
}

void display(char array[])
{
    puts("\n");
    puts(array);
}
void reverse(char *type)
{
    int icounter1, icounter2;
    char character;
    for (icounter1 = 0, icounter2 = strlen(type); icounter1 < icounter2 / 2; icounter1++)
    {
        character = type[icounter1];
        type[icounter1] = type[icounter2 - icounter1 - 1];
        type[icounter2 - icounter1 - 1] = character;
    }
}
int words(char *array)
{
    int icounter1, icounter2;
    int wordcount = 0;
    for (icounter1 = 0, icounter2 = strlen(array); icounter1 < icounter2; icounter1++)
        if ((array[icounter1 + 1] == ' ' || array[icounter1 + 1] == '\0') && array[icounter1] != ' ')
            wordcount++;
    return wordcount;
}

void main()
{
    char choice;
    char type_default[] = "";
    char *type = type_default;
    while ((choice = menu()) != '0')
    {
        getchar();
        switch (choice)
        {
        case '1':
            type = storing();
            break;
        case '2':
            display(type);
            break;
        case '3':
            printf("\n%d", words(type));
            break;
        case '4':
            reverse(type);
            break;
        default:
            printf("\ninvalid choice");
        }
        printf("\n type to return to the menu \n");
    }
}