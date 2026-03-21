#include <stdio.h>

// 1. Define the struct AND create variables (a, b) at the tail
struct Player {
    int score;
    char level;
} p1 = {95, 'A'}, p2 = {40, 'F'}; 
// p1 and p2 are now global variables of type 'struct Player'

int main() {
    // 2. Use them in a condition just like normal variables
    // We access the "internal" data using the dot (.) operator
    if (p1.score > 50) {
        printf("Player 1 Passed!\n");
    } else {
        printf("Player 1 Failed.\n");
    }

    // 3. Print them like normal variables
    // Note: You must specify which 'part' of the struct you want to print
    printf("P1 Score: %d, P1 Level: %c\n", p1.score, p1.level);
    printf("P2 Score: %d, P2 Level: %c\n", p2.score, p2.level);

    return 0;
}
