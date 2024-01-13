/*
Write a program that reads from a text file 10 integer numbers.
The file has to be previously created by program or externally by using the operating system's facilities.
Write the functions that:
- order the integers array in ascending/descending order and displays the result
- count the number of even numbers in the array and display the result
*/

#include <iostream>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool compareDesc(int a, int b)
{
    return a < b;
}

bool compareAsc(int a, int b)
{
    return b < a;
}

void bubbleSort(int arr[], int n, bool (*compare)(int, int)) 
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = false;

        for (j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

int countEvenNumbers(int arr[], int n) 
{
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

    const int n = 10;
    int numbers[n];
    for (int i = 0; i < n; i++) {
        fscanf_s(file, "%d ", &numbers[i]);
    }

    fclose(file);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bubbleSort(numbers, n, compareAsc);
    printf("Ascending Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bubbleSort(numbers, n, compareDesc);
    printf("Descending Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int evenCount = countEvenNumbers(numbers, n);
    printf("Number of Even Numbers: %d\n", evenCount);

    return 0;
}