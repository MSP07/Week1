FIND THE Kth SMALLEST ELEMENT IN AN ARRAY

#include <stdio.h>

int kthSmallest(int arr[], int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr[k - 1];
}

int main() {
    int arr[] = {7, 4, 6, 3, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("k'th smallest array element is %d\n", kthSmallest(arr, n, k));
    return 0;
}
