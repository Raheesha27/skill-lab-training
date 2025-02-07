#include <stdio.h>

int main() {
    // Example sales data for 7 days
    int sales[] = {150, 200, 300, 250, 400, 350, 450};
    int numberOfDays = sizeof(sales) / sizeof(sales[0]);
    
    // Initialize maxSales to the first element and dayWithMaxSales to 0
    int maxSales = sales[0];
    int dayWithMaxSales = 0;

    // Loop through the sales array to find the maximum sales
    for (int i = 1; i < numberOfDays; i++) {
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            dayWithMaxSales = i; // Update the day index
        }
    }

    // Output the result
    printf("Day with highest sales: Day %d with sales amount: %d\n", dayWithMaxSales + 1, maxSales);

    return 0;
}
