COPYING HERO


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, target, steps = 0;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    target = 1;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            target++;
        }
    }
    target--;
    for (i = 0; i < n; i++) {
        if (arr[i] < target) {
            steps += target - arr[i];
        } else if (arr[i] > target) {
            steps += arr[i] - target;
        }
    }
    printf("%d\n", steps);
    free(arr);
    return 0;
}
