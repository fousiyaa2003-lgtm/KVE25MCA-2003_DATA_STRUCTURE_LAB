#include <stdio.h>

int main()
{
    int i, j, n1, n2, n3, temp;

    printf("Enter the size of first array: ");
    scanf("%d", &n1);
    int a[n1];

    printf("Enter the elements of first array:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter the size of second array: ");
    scanf("%d", &n2);
    int b[n2];

    printf("Enter the elements of second array:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    // Merging two arrays
    n3 = n1 + n2;
    int c[n3];

    for(i = 0; i < n1; i++)
        c[i] = a[i];

    for(i = 0; i < n2; i++)
        c[i + n1] = b[i];

    printf("\nMerged Array: ");
    for(i = 0; i < n3; i++)
        printf("%d ", c[i]);

    // Sorting the merged array
    for(i = 0; i < n3; i++) {
        for(j = i + 1; j < n3; j++) {
            if(c[i] > c[j]) {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for(i = 0; i < n3; i++)
        printf("%d ", c[i]);

    return 0;
}

