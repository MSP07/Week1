MAX SUM RUPEES

#include <stdio.h>

int main() {
    int t, n, m, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        int a[n], b[m], pa = 0, pb = 0, ans = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        while (pa < n && pb < m) {
            if (a[pa] < b[pb]) {
                ans += a[pa++];
            } else if (a[pa] > b[pb]) {
                ans += b[pb++];
            } else {
                int sum_a = a[pa++], sum_b = b[pb++];
                while (pa < n && pb < m && a[pa] == b[pb]) {
                    sum_a += a[pa++];
                    sum_b += b[pb++];
                }
                ans += (sum_a > sum_b) ? sum_a : sum_b;
            }
        }
        while (pa < n) {
            ans += a[pa++];
        }
        while (pb < m) {
            ans += b[pb++];
        }
        printf("%d\n", ans);
    }
    return 0;
}
