#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000

int main() {
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: numbers.txt file not found.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    int arr[n];
    int freq[MAX_VAL] = {0}; 

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
        freq[arr[i]]++; 
    }

    fclose(file);

  
    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int duplicateCount = 0;
    int maxFreq = 0;
    int mostRepeated = arr[0];

    for (int i = 0; i < MAX_VAL; i++) {
        if (freq[i] > 1) {
            duplicateCount++;
        }
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostRepeated = i;
        }
    }

    printf("Total number of duplicate values = %d\n", duplicateCount);
    printf("The most repeating element in the array = %d\n", mostRepeated);

    return 0;
}
