#include <stdio.h>
#include <stdlib.h>

void calculatePostfixSum(int Fuel[], int PostfixSum[], int m) {
    // Initialize the last element of PostfixSum
    PostfixSum[m - 1] = Fuel[m - 1];

    // Calculate the postfix sums
    for (int i = m - 2; i >= 0; i--) {
        PostfixSum[i] = PostfixSum[i + 1] + Fuel[i];
    }
}

int main() {
    int m;

    // Ask the user for the number of delivery points
    printf("Enter the number of delivery points: ");
    scanf("%d", &m);

    // Check if the number of delivery points is valid
    if (m <= 0) {
        printf("The number of delivery points must be greater than 0.\n");
        return 1; // Exit if the input is invalid
    }

    // Dynamically allocate memory for Fuel and PostfixSum
    int *Fuel = (int *)malloc(m * sizeof(int));
    int *PostfixSum = (int *)malloc(m * sizeof(int));

    if (Fuel == NULL || PostfixSum == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Get fuel consumption values from the user
    printf("Enter the fuel consumption values for each delivery point:\n");
    for (int i = 0; i < m; i++) {
        printf("Fuel[%d]: ", i);
        scanf("%d", &Fuel[i]);
    }

    // Calculate postfix sums
    calculatePostfixSum(Fuel, PostfixSum, m);

    // Print the result
    printf("PostfixSum[] = [");
    for (int i = 0; i < m; i++) {
        printf("%d", PostfixSum[i]);
        if (i < m - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    free(Fuel);
    free(PostfixSum);

    return 0;
}
