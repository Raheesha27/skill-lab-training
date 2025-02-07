#include <stdio.h>

#define MAX_RATINGS 5 // Assuming ratings are from 1 to 5

int main() {
    // Example product ratings
    int ratings[] = {5, 3, 4, 5, 2, 3, 5, 4, 2, 1, 3, 4, 5};
    int numberOfRatings = sizeof(ratings) / sizeof(ratings[0]);
    
    // Array to count occurrences of each rating
    int count[MAX_RATINGS + 1] = {0}; // Index 0 will be unused

    // Count occurrences of each rating
    for (int i = 0; i < numberOfRatings; i++) {
        if (ratings[i] >= 1 && ratings[i] <= MAX_RATINGS) {
            count[ratings[i]]++;
        }
    }

    // Find the rating with the maximum occurrences
    int maxCount = 0;
    int mostFrequentRating = 0;

    for (int i = 1; i <= MAX_RATINGS; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequentRating = i;
        }
    }

    // Output the result
    printf("The most frequently occurring rating is: %d with %d occurrences.\n", mostFrequentRating, maxCount);

    return 0;
}
