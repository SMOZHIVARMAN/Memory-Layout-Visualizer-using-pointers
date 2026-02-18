#ifndef MEMORY_H
#define MEMORY_H

int* createArray(int size);
void inputArray(int* arr, int size);
void printMemoryMap(int* arr, int size);
void freeMemory(int* arr);
void writeToJSON(int* arr, int size);

#endif
