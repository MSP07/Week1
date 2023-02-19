CLOSEST NUMBERS


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* closestNumbers(int arr_count, int* arr, int* result_count) {
    qsort(arr, arr_count, sizeof(int), cmpfunc);
    int min_diff = INT_MAX;
    int count = 0;

    for (int i = 0; i < arr_count - 1; i++) {
        int diff = abs(arr[i] - arr[i+1]);
        if (diff < min_diff) {
            min_diff = diff;
            count = 1;
        } else if (diff == min_diff) {
            count++;
        }
    }

    int* result = (int*)malloc(sizeof(int) * count * 2);
    int index = 0;
    for (int i = 0; i < arr_count - 1; i++) {
        int diff = abs(arr[i] - arr[i+1]);
        if (diff == min_diff) {
            result[index++] = arr[i];
            result[index++] = arr[i+1];
        }
    }

    *result_count = count * 2;
    return result;
}

int main() {
    int arr_count;
    scanf("%d", &arr_count);

    int arr[arr_count];
    for (int i = 0; i < arr_count; i++) {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int* result = closestNumbers(arr_count, arr, &result_count);

    for (int i = 0; i < result_count; i += 2) {
        printf("%d %d\n", result[i], result[i+1]);
    }

    free(result);

    return 0;
}
