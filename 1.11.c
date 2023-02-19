LARGEST SUBARRAY WITH 0 SUM


#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int largestSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;
    int hashTable[2 * n + 1];
    for (int i = 0; i < 2 * n + 1; i++) {
        hashTable[i] = -1;
    }
    hashTable[n] = 0; 

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            maxLen = i + 1;
        }
        if (hashTable[sum + n] != -1) {
            maxLen = max(maxLen, i - hashTable[sum + n]);
        } else {
            hashTable[sum + n] = i;
        }
    }
    return maxLen;
}

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxLen = largestSubarray(arr, n);
    printf("%d", maxLen);
    return 0;
}
