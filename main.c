#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "pointer_ops.h"

int main() {

    int size;
    int mode;

    printf("Enter the size of the array: ");

    /* Safe input validation */
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input for size.\n");
        return 1;
    }

    int* arr = createArray(size);

    if (arr == NULL) {
        return 1;
    }

    inputArray(arr, size);
    printMemoryMap(arr, size);
    writeToJSON(arr, size);
    
    printf("\nSelect Mode:\n");
printf("1. Single Pointer Mode\n");
printf("2. Dual Pointer Mode\n");
printf("3. Memory Internal Analysis Mode\n");
printf("Enter choice: ");

if (scanf("%d", &mode) != 1) {
    printf("Invalid mode input.\n");
    freeMemory(arr);
    return 1;
}

if (mode == 1) {
    startSinglePointerEngine(arr, size);
}
else if (mode == 2) {
    startDualPointerEngine(arr, size);
}
else if (mode == 3) {
    memoryInternalAnalysis(arr, size);
}
else {
    printf("Invalid mode selected.\n");
}

    freeMemory(arr);

    return 0;
}
