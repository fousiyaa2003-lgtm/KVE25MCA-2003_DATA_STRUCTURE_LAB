#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

int main() {
    int setA[MAX_ELEMENTS], setB[MAX_ELEMENTS];
    int limitA, limitB, i, j;

    // --- Input Set A ---
    printf("Enter the number of elements in the first set \n");
    scanf("%d", &limitA);
    printf("Enter the elements of set A \n");
    for (i = 0; i < limitA; i++) {
        scanf("%d", &setA[i]);
    }

    // --- Input Set B ---
    printf("Enter the number of elements in the second set \n");
    scanf("%d", &limitB);
    printf("Enter the elements of set B \n");
    for (i = 0; i < limitB; i++) {
        scanf("%d", &setB[i]);
    }

    // --- Print Set A ---
    printf("setA = { ");
    for (i = 0; i < limitA; i++) {
        printf("%d, ", setA[i]);
    }
    printf("\b\b } \n"); // \b is backspace to remove trailing comma

    // --- Print Set B ---
    printf("setB = { ");
    for (i = 0; i < limitB; i++) {
        printf("%d, ", setB[i]);
    }
    printf("\b\b } \n");

    // --- 1. Union (A U B) ---
    // Logic: Print all A, then print B if it is NOT in A
    printf("Union of sets A and B = { ");
    // Print all of A first
    for (i = 0; i < limitA; i++) {
        printf("%d, ", setA[i]);
    }
    // Check B against A
    for (i = 0; i < limitB; i++) {
        int isDuplicate = 0;
        for (j = 0; j < limitA; j++) {
            if (setB[i] == setA[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            printf("%d, ", setB[i]);
        }
    }
    printf("\b\b } \n");

    // --- 2. Intersection (A n B) ---
    // Logic: Print elements present in BOTH A and B
    printf("Intersection of set A and B = { ");
    for (i = 0; i < limitA; i++) {
        for (j = 0; j < limitB; j++) {
            if (setA[i] == setB[j]) {
                printf("%d, ", setA[i]);
                break; // Break to avoid double printing if B has duplicates
            }
        }
    }
    printf("\b\b } \n");

    // --- 3. Set Difference (A - B) ---
    // Logic: Print elements in A that are NOT in B
    printf("Set Difference A - B = { ");
    for (i = 0; i < limitA; i++) {
        int isDuplicate = 0;
        for (j = 0; j < limitB; j++) {
            if (setA[i] == setB[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            printf("%d, ", setA[i]);
        }
    }
    printf("\b\b } \n");

    return 0;
}
