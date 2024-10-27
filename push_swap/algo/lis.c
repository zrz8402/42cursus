#include <stdio.h>
#include <stdlib.h>

void longest_increasing_subsequence(int arr[], int n) {
    if (n == 0) {
        printf("The array is empty.\n");
        return;
    }

    int *dp = (int *)malloc(n * sizeof(int));
    int *prev = (int *)malloc(n * sizeof(int));
    int maxLength = 1, maxIndex = 0;

    // Initialize dp and prev
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }

    // Build the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    // Backtrack to find the LIS and its indices
    int *lis = (int *)malloc(maxLength * sizeof(int));
    int *indices = (int *)malloc(maxLength * sizeof(int));
    int k = maxLength - 1;

    while (maxIndex != -1) {
        lis[k] = arr[maxIndex];
        indices[k] = maxIndex;
        maxIndex = prev[maxIndex];
        k--;
    }

    // Print the results
    printf("Longest Increasing Subsequence: ");
    for (int i = 0; i < maxLength; i++) {
        printf("%d ", lis[i]);
    }
    printf("\nIndices: ");
    for (int i = 0; i < maxLength; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    // Free allocated memory
    free(dp);
    free(prev);
    free(lis);
    free(indices);
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    longest_increasing_subsequence(arr, n);

    return 0;
}
