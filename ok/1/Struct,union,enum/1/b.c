#include <stdio.h>

// 1. Define the enum AND create variables at the tail
// By default: LOW = 0, MEDIUM = 1, HIGH = 2
enum Difficulty {
    LOW, 
    MEDIUM, 
    HIGH
} level1 = LOW, level2 = HIGH;

int main() {
    // 2. Use them in conditions like normal variables
    if (level2== HIGH) {
        printf("Game is starting on Easy mode.\n");
    }

    // 3. Print them (Enums are actually just integers!)
    printf("Level 1 Value: %d\n", level1); // Prints 0
    printf("Level 2 Value: %d\n", level2); // Prints 2

    // 4. Changing a value
    level1 = MEDIUM;
    
    if (level1 > LOW) {
        printf("The difficulty has increased to %d!\n", level1);
    }

    return 0;
}
