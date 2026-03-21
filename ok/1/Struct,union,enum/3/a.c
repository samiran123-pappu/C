#include <stdio.h>

// 1. STRUCT: All members have their own separate space in memory.
struct Stats {
    int hp;
    int mp;
} player1 = {100, 50}; // 'player1' is a variable at the tail

// 2. UNION: All members SHARE the same memory space. 
// Only one can be used at a time.
union Value {
    int i;
    float f;
} data = {10}; // 'data' is a variable at the tail (initializes the first member)

// 3. ENUM: Assigns names to numbers (0, 1, 2...).
enum Mode {
    EASY, 
    HARD
} currentMode = EASY; // 'currentMode' is a variable at the tail

int main() {
    // --- Accessing the STRUCT ---
    printf("Player HP: %d, MP: %d\n", player1.hp, player1.mp);

    // --- Accessing the UNION ---
    printf("Union Integer: %d\n", data.i);
    data.f = 3.14; // Overwrites the integer 'i' because they share memory
    printf("Union Float: %.2f\n", data.f);

    // --- Accessing the ENUM ---
    if (currentMode == EASY) {
        printf("Current Game Mode: %d (EASY)\n", currentMode);
    }

    return 0;
}
