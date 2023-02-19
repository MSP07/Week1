SUM OF ELEMENTS LESS THAN A AND GREATER THAN B IN AN ARRAY

#include <stdio.h>

int main() {
    int n, q, x, y, i, count;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    while (q--) {
        count = 0;
        scanf("%d %d", &x, &y);
        for (i = 0; i < n; i++) {
            if (a[i] < x) {
                count += a[i];
            }
            else if (a[i] > y) {
                count += a[i];
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
