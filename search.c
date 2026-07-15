#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    int i, j;

    if (needle[0] == '\0')
        return 0;

    for (i = 0; haystack[i] != '\0'; i++)
    {
        j = 0;

        while (needle[j] != '\0' &&
               haystack[i + j] == needle[j])
        {
            j++;
        }

        if (needle[j] == '\0')
            return i;
    }

    return -1;
}

int main()
{
    char haystack[100], needle[100];

    printf("Enter the main string: ");
    scanf("%99[^\n]", haystack);

    getchar();

    printf("Enter the substring: ");
    scanf("%99[^\n]", needle);

    int index = find_substring(haystack, needle);

    if (index == -1)
        printf("Substring not found\n");
    else
        printf("Substring found at index %d\n", index);

    return 0;
}
