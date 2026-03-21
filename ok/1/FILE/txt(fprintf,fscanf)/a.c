#include <stdio.h>

int main() {
    FILE *fptr;
    int id = 101;
    char grade = 'A';
    float score = 92.5;

    // 1. OPEN for Writing (Text Mode)
    fptr = fopen("student.txt", "w");
    if (fptr != NULL) {
        // fprintf works just like printf, but sends data to the file
        fprintf(fptr, "%d %c %.2f", id, grade, score);
        fclose(fptr);
        printf("Data written to file successfully.\n");
    }

    // Variables to hold the data we read back
    int id_in;
    char grade_in;
    float score_in;

    // 2. OPEN for Reading (Text Mode)
    fptr = fopen("student.txt", "r");
    if (fptr != NULL) {
        // fscanf reads the formatted text and stores it in memory addresses (&)
        // It looks for the exact pattern: integer, then char, then float
        fscanf(fptr, "%d %c %f", &id_in, &grade_in, &score_in);
        fclose(fptr);

        // Display the "read" data to prove it worked
        printf("Read from file: ID: %d, Grade: %c, Score: %.1f\n", id_in, grade_in, score_in);
    } else {
        printf("Error: Could not open file for reading.\n");
    }

    return 0;
}
