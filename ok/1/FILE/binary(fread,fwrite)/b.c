#include <stdio.h>

// Our custom data type
struct Robot {
    int id;
    float battery;
};

int main() {
    struct Robot myBot = {7, 88.5}; // The data to save
    struct Robot importedBot;       // The variable to hold the data we read back
    FILE *fptr;

    // 1. WRITE in Binary Mode ("wb")
    fptr = fopen("robot.bin", "wb");
    if (fptr != NULL) {
        // Arguments: (Address of data, Size of 1 item, How many items, File pointer)
        fwrite(&myBot, sizeof(struct Robot), 1, fptr);
        fclose(fptr);
        printf("Binary data saved to 'robot.bin'\n");
    }

    // 2. READ in Binary Mode ("rb")
    fptr = fopen("robot.bin", "rb");
    if (fptr != NULL) {
        // fread copies the raw bits from the file into the address of 'importedBot'
        fread(&importedBot, sizeof(struct Robot), 1, fptr);
        fclose(fptr);

        // Prove it worked
        printf("Read from Binary: ID %d, Battery %.1f%%\n", importedBot.id, importedBot.battery);
    }

    return 0;
}
