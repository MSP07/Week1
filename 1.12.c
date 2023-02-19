ARRANGE IN LEXICOGRAPHICAL

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

void countingSort(char arr[])
{
    int count[MAX_CHAR] = {0};
    int length = strlen(arr);
    
    for(int i = 0; i < length; i++)
    {
        count[arr[i] - 'a']++;
    }

    for(int i = 1; i < MAX_CHAR; i++)
    {
        count[i] += count[i - 1];
    }

    char output[length];
    for(int i = length - 1; i >= 0; i--)
    {
        output[count[arr[i] - 'a'] - 1] = arr[i];
        count[arr[i] - 'a']--;
    }

    for(int i = 0; i < length; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    char arr[100];
    printf("Enter the string: ");
    scanf("%s", arr);
    countingSort(arr);
    printf("The string in lexicographical order is: %s\n", arr);
    return 0;
}
