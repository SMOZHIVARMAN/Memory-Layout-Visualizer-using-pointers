#include <stdio.h>
#include "pointer_ops.h"

/* ================== ASCII Visualization ================== */

void visualizeMemorySingle(int* arr, int size, int* ptr) {

    printf("\nMemory Layout:\n");

    for (int i = 0; i < size; i++)
        printf("| %d ", arr[i]);

    printf("|\n");

    for (int i = 0; i < size; i++) {
        if (&arr[i] == ptr)
            printf("  ^  ");
        else
            printf("     ");
    }

    printf("\n");
}

void visualizeMemoryDual(int* arr, int size, int* ptr1, int* ptr2) {

    printf("\nMemory Layout:\n");

    for (int i = 0; i < size; i++)
        printf("| %d ", arr[i]);

    printf("|\n");

    for (int i = 0; i < size; i++) {

        if (&arr[i] == ptr1 && &arr[i] == ptr2)
            printf("  *  ");     // both pointers
        else if (&arr[i] == ptr1)
            printf("  ^  ");     // pointer 1
        else if (&arr[i] == ptr2)
            printf("  #  ");     // pointer 2
        else
            printf("     ");
    }

    printf("\n");
}

/* ================== SINGLE POINTER ENGINE ================== */

void startSinglePointerEngine(int* arr, int size) {

    int* ptr = arr;
    int choice;

    while (1) {

        printf("\n--- Single Pointer Engine ---\n");
        printf("Current Index  : %ld\n", ptr - arr);
        printf("Current Address: %p\n", (void*)ptr);
        printf("Current Value  : %d\n", *ptr);

        visualizeMemorySingle(arr, size, ptr);

        printf("\n1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Jump by Offset\n");
        printf("4. Modify Value\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {

            case 1:
                if (ptr < arr + size - 1)
                    ptr++;
                else
                    printf("Boundary reached.\n");
                break;

            case 2:
                if (ptr > arr)
                    ptr--;
                else
                    printf("Start boundary reached.\n");
                break;

            case 3: {
                int offset;
                printf("Enter offset: ");

                if (scanf("%d", &offset) != 1) {
                    printf("Invalid offset input.\n");
                    break;
                }

                if (ptr + offset >= arr && ptr + offset < arr + size)
                    ptr += offset;
                else
                    printf("Invalid offset. Boundary violation prevented.\n");
                break;
            }

            case 4: {
                int newValue;
                printf("Enter new value: ");

                if (scanf("%d", &newValue) != 1) {
                    printf("Invalid value input.\n");
                    break;
                }

                *ptr = newValue;
                printf("Value updated successfully.\n");
                break;
            }

            case 5:
                printf("Exiting Single Pointer Engine...\n");
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}

/* ================== DUAL POINTER ENGINE ================== */

void startDualPointerEngine(int* arr, int size) {

    int* ptr1 = arr;
    int* ptr2 = arr + size - 1;
    int choice;

    while (1) {

        printf("\n--- Dual Pointer Engine ---\n");

        printf("\nPointer 1 -> Index: %ld | Address: %p | Value: %d\n",
               ptr1 - arr, (void*)ptr1, *ptr1);

        printf("Pointer 2 -> Index: %ld | Address: %p | Value: %d\n",
               ptr2 - arr, (void*)ptr2, *ptr2);

        visualizeMemoryDual(arr, size, ptr1, ptr2);

        printf("\n1. Move Pointer 1 Forward\n");
        printf("2. Move Pointer 1 Backward\n");
        printf("3. Move Pointer 2 Forward\n");
        printf("4. Move Pointer 2 Backward\n");
        printf("5. Compare Pointers\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {

            case 1:
                if (ptr1 < arr + size - 1)
                    ptr1++;
                else
                    printf("Pointer 1 reached boundary.\n");
                break;

            case 2:
                if (ptr1 > arr)
                    ptr1--;
                else
                    printf("Pointer 1 at start boundary.\n");
                break;

            case 3:
                if (ptr2 < arr + size - 1)
                    ptr2++;
                else
                    printf("Pointer 2 reached boundary.\n");
                break;

            case 4:
                if (ptr2 > arr)
                    ptr2--;
                else
                    printf("Pointer 2 at start boundary.\n");
                break;

            case 5:
                printf("\nPointer Difference (ptr2 - ptr1) = %ld elements\n",
                       ptr2 - ptr1);

                if (ptr1 == ptr2)
                    printf("Both pointers point to same location.\n");
                else if (ptr1 < ptr2)
                    printf("Pointer 1 is before Pointer 2.\n");
                else
                    printf("Pointer 1 is after Pointer 2.\n");
                break;

            case 6:
                printf("Exiting Dual Pointer Engine...\n");
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void memoryInternalAnalysis(int* arr, int size) {

    printf("\n--- Memory Internal Analysis Mode ---\n");

    printf("Size of int: %lu bytes\n", sizeof(int));

    printf("Base Address (arr): %p\n", (void*)arr);
    printf("Address of arr[0]: %p\n", (void*)&arr[0]);
    printf("Address of arr[1]: %p\n", (void*)&arr[1]);
    printf("Last Element Address: %p\n", (void*)&arr[size - 1]);

    printf("\nTotal Memory Allocated: %lu bytes\n",
           size * sizeof(int));

    printf("\nAddress Difference between arr[1] and arr[0]: %ld bytes\n",
           (char*)&arr[1] - (char*)&arr[0]);

    printf("Pointer Subtraction (arr+1 - arr): %ld elements\n",
           (&arr[1] - &arr[0]));

    printf("\nExplanation:\n");
    printf("When you do ptr + 1, pointer moves by sizeof(int) bytes.\n");
    printf("Pointer subtraction gives number of elements between addresses.\n");

    printf("\n------------------------------------------\n");
}
