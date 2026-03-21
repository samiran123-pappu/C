#include <stdio.h>

int main()
{

    FILE *fp = fopen("info.txt", "w");
    int age = 20;
    fprintf(fp, "%d", age); // Stores the characters '2' and '0' (2 bytes)
    fclose(fp);

    fp = fopen("info.txt", "r");
    fscanf(fp, "%d", &age); // Converts '20' back into an integer
    fclose(fp);

    return 0;
}