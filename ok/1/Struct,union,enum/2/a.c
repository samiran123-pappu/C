#include <stdio.h>

// 1. TYPEDEF + STRUCT + TAIL VARIABLE
typedef struct Laptop {
    char brand[20];
    int ram_gb;
    float price;
} Laptop; // 'Laptop' is now the Type Name (the alias)

// 2. We can create a variable at the tail too!
Laptop myTablet = {"iPad Pro", 8, 799.99};

int main() {
    // 3. Create a second variable using the NEW Type Name (Laptop)
    Laptop schoolTab = {"Surface Go", 4, 399.50};

    // 4. Use them in a condition
    if (myTablet.ram_gb > schoolTab.ram_gb) {
        printf("%s is more powerful than %s!\n", myTablet.brand, schoolTab.brand);
    }

    // 5. Print them like normal variables using the dot (.) operator
    printf("Tablet 1: %s | RAM: %dGB | Price: $%.2f\n", 
            myTablet.brand, myTablet.ram_gb, myTablet.price);

    return 0;
}
