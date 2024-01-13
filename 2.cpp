/*
Write a program that reads from a text file 10 integer numbers.
The file has to be previously created by program or externally by using the operating system's facilities.
Write the functions that:
- order the integers array in ascending/descending order and displays the result
- count the number of even numbers in the array and display the result
*/

#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int ascending) {
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}

int countEvenNumbers(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}


int main()
{
    printf("Enter the filename (max 100 chars): ");

    const int size = 101;

    char filename[size];

    scanf_s("%s", filename, size);

    printf("You entered: %s\n", filename);

    FILE* file;
    fopen_s(&file, filename, "w+");

    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    const char* numberString = "5 3 2 8 1 4 7 6 10 9";

    fputs(numberString, file);

    fclose(file);

    fopen_s(&file, filename, "r");

    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    int numbers[10];
    for (int i = 0; i < 10; i++) {
        fscanf_s(file, "%d ", &numbers[i]);
    }

    fclose(file);

    printf("Original Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bubbleSort(numbers, 10, 1);
    printf("Ascending Order: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bubbleSort(numbers, 10, 0);
    printf("Descending Order: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int evenCount = countEvenNumbers(numbers, 10);
    printf("Number of Even Numbers: %d\n", evenCount);

    return 0;
}