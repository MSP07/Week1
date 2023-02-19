BIG SORTING


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int compare(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    if (len_a < len_b) {
        return -1;
    } else if (len_a > len_b) {
        return 1;
    } else {
        return strcmp(str_a, str_b);
    }
}

char **bigSorting(int unsorted_count, char **unsorted, int *result_count) {
    qsort(unsorted, unsorted_count, sizeof(char *), compare);
    *result_count = unsorted_count;
    return unsorted;
}

int main() {
    int n;
    char **unsorted = malloc(MAX_SIZE * sizeof(char *));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        unsorted[i] = malloc(1001 * sizeof(char));
        scanf("%s", unsorted[i]);
    }
    int result_count;
    char **result = bigSorting(n, unsorted, &result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%s\n", result[i]);
    }
    for (int i = 0; i < n; i++) {
        free(unsorted[i]);
    }
    free(unsorted);
    return 0;
}
