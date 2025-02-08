#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10 // Digits from 0 to 9

void findDistinctDigits(int N[], int k, int distinctDigits[]) {
    // Initialize the distinctDigits array to 0
    for (int i = 0; i < MAX_DIGITS; i++) {
        distinctDigits[i] = 0;
    }

    // Iterate through each number in the array
    for (int i = 0; i < k; i++) {
        int number = N[i];
        
        // Extract digits from the number
        while (number > 0) {
            int digit = number % 10; // Get the last digit
            distinctDigits[digit] = 1; // Mark this digit as found
            number /= 10; // Remove the last digit
        }
    }
}

void printDistinctDigits(int distinctDigits[]) {
    printf("[");
    int first = 1; // Flag to handle comma placement
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (distinctDigits[i] == 1) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0; // Set flag to false after the first digit
        }
    }
    printf("]\n");
}

int main() {
    int k;

    // Ask the user for the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &k);

    // Dynamically allocate memory for the array of integers
    int *N = (int *)malloc(k * sizeof(int));
    if (N == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Get the integers from the user
    printf("Enter the integers:\n");
    for (int i = 0; i < k; i++) {
        printf("N[%d]: ", i);
        scanf("%d", &N[i]);
    }

    // Array to hold distinct digits
    int distinctDigits[MAX_DIGITS] = {0};

    // Find distinct digits
    findDistinctDigits(N, k, distinctDigits);

    // Print the distinct digits
    printDistinctDigits(distinctDigits);

    // Free allocated memory
    free(N);

    return 0;
}
