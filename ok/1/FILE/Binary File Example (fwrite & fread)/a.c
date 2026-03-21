#include <stdio.h>

int main()
{

    struct Data
    {
        int id;
        float val;
    } d1 = {101, 5.5}, d2;

    FILE *fp = fopen("data.bin", "wb");
    // Writes the entire block of memory occupied by the struct
    fwrite(&d1, sizeof(struct Data), 1, fp);
    fclose(fp);

    fp = fopen("data.bin", "rb");
    // Reads that exact block of memory back into d2
    fread(&d2, sizeof(struct Data), 1, fp);
    fclose(fp);

    return 0;
}