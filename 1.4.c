AMAN ARITHMETIC PROGRESSION

#include <stdio.h>

int main() {
    int n, i, j, k, count = 0, first, second, diff;
    
    // Reading input
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Checking if the given sequence is already an AP
    if(n <= 2) {
        printf("0\n");
        return 0;
    }
    else {
        diff = arr[1] - arr[0];
        for(i=2; i<n; i++) {
            if(arr[i] - arr[i-1] != diff) {
                break;
            }
        }
        if(i == n) {
            printf("0\n");
            return 0;
        }
    }
    
    // Adding new numbers to check for AP
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            first = arr[i];
            second = arr[j];
            diff = second - first;
            count = 0;
            for(k=0; k<n; k++) {
                if(k == i || k == j) {
                    continue;
                }
                if(arr[k] - first == (k-i)*diff || first - arr[k] == (k-i)*diff) {
                    count++;
                }
            }
            if(count == n-2) {
                printf("2\n%d %d\n", first-diff, second+diff);
                return 0;
            }
        }
    }
    
    printf("0\n");
    return 0;
}
