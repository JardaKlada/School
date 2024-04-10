#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: 0! and 1! are both 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int num;

    // Input: Get a number from the user
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if the number is non-negative
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        // Output: Calculate and print the factorial
        printf("Factorial of %d = %llu\n", num, factorial(num));
    }

    return 0;
}
