#include <stdio.h>

void calculatePrefixSum(int Sales[], int PrefixSum[], int n) {
    // Initialize the first element of PrefixSum
    PrefixSum[0] = Sales[0];

    // Calculate the prefix sums
    for (int i = 1; i < n; i++) {
        PrefixSum[i] = PrefixSum[i - 1] + Sales[i];
    }
}

int main() {
    // Example input
    int Sales[] = {10, 20, 15, 30, 25};
    int n = sizeof(Sales) / sizeof(Sales[0]);
    int PrefixSum[n];

    // Calculate prefix sums
    calculatePrefixSum(Sales, PrefixSum, n);

    // Print the result
    printf("PrefixSum[] = [");
    for (int i = 0; i < n; i++) {
        printf("%d", PrefixSum[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
