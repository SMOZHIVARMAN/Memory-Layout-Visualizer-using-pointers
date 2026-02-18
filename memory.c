#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/* Create dynamic array */
int* createArray(int size) {
    if (size <= 0) {
        printf("Invalid size.\n");
        return NULL;
    }

    int* arr = (int*) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    return arr;
}

/* Take input */
void inputArray(int* arr, int size) {
    printf("Enter %d elements:\n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

/* Print memory map */
void printMemoryMap(int* arr, int size) {

    printf("\nMemory Map:\n");
    printf("-------------------------------------------------\n");
    printf("Index\tAddress\t\t\tValue\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%p\t%d\n", i, (void*)&arr[i], arr[i]);
    }

    printf("-------------------------------------------------\n");
}

/* Write array to JSON file */
void writeToJSON(int* arr, int size) {

    FILE* file = fopen("output.json", "w");

    if (file == NULL) {
        printf("Error creating JSON file.\n");
        return;
    }

    fprintf(file, "{\n");
    fprintf(file, "  \"size\": %d,\n", size);
    fprintf(file, "  \"elements\": [");

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d", arr[i]);
        if (i != size - 1)
            fprintf(file, ", ");
    }

    fprintf(file, "]\n");
    fprintf(file, "}\n");

    fclose(file);

    printf("JSON file updated successfully.\n");
}

/* Free memory */
void freeMemory(int* arr) {
    free(arr);
    printf("Memory freed successfully.\n");
}
