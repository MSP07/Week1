CHOCOLATE

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t, n, k, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        int a[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmpfunc);
        int prefix_sum[n+1];
        prefix_sum[0] = 0;
        for (i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + a[i-1];
        }
        int dp[n+1][n+1];
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                if (j == 1) {
                    dp[i][j] = prefix_sum[i];
                } else {
                    dp[i][j] = dp[i-1][j];
                    for (int l = 1; l < i; l++) {
                        if (dp[i][j] > dp[l][j-1] + (prefix_sum[i] - prefix_sum[l]) + j * (prefix_sum[l])) {
                            dp[i][j] = dp[l][j-1] + (prefix_sum[i] - prefix_sum[l]) + j * (prefix_sum[l]);
                        }
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            printf("%d ", dp[n][i]);
        }
        printf("\n");
    }
    return 0;
}
