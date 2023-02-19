ANTS ON A CIRCLE

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, l, k;
    scanf("%d %d %d", &n, &l, &k);
    int pos[n], dir[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i], &dir[i]);
    }
    for (int i = 0; i < n; i++) {
        if (dir[i] == 1) {
            pos[i] = (pos[i] + k) % l;
        } else {
            pos[i] = (pos[i] - k + l) % l;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pos[i] > pos[j]) {
                int tmp = pos[i];
                pos[i] = pos[j];
                pos[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", pos[i]);
    }
    printf("\n");
    return 0;
}
