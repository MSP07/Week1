CHECK IF TWO ARRAYS ARE EQUAL OR NOT

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool areEqual(int A[], int B[], int n) {
    int freqA[MAX_SIZE] = {0};
    int freqB[MAX_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        freqA[A[i]]++;
    }

    for (int i = 0; i < n; i++) {
        freqB[B[i]]++;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (freqA[i] != freqB[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    int A[MAX_SIZE], B[MAX_SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    if (areEqual(A, B, n)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
