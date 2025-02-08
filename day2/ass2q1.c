#include <stdio.h>

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    // Conditions are checked to ensure that i doesn't exceed mid and j doesn't exceed right
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There are mid - i inversions, because all elements left to i in the left subarray
            // are greater than arr[j]
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into Original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int countInversions(int arr[], int n) {
    int temp[n]; // Temporary array to help with merging
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int P[] = {30, 45, 25, 60, 20};
    int n1 = sizeof(P) / sizeof(P[0]);
    int result1 = countInversions(P, n1);
    printf("The inversion count for P[] = {30, 45, 25, 60, 20} is %d\n", result1);

    int A[] = {1, 9, 6, 4, 5};
    int n2 = sizeof(A) / sizeof(A[0]);
    int result2 = countInversions(A, n2);
    printf("The inversion count for A[] = {1, 9, 6, 4, 5} is %d\n", result2);

    return 0;
}
