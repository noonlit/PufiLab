/*
Write a program that reads from the keyboard n integer values and then stores them into a text file. 
The filename has to be read from the keyboard. 
Then read the numbers from the file, calculate their average value, display-it and append-it to the end of the text-file.
*/

#include <iostream>

int main()
{
    int n;

    printf("Enter the number of integer values: ");
    scanf_s("%d", &n);

    // Create an array to store the entered values, dynamically allocated on the heap
    int size = sizeof(int) * n;
    int* values = (int*)(malloc(size));

    printf("Enter %d integer values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &values[i]);
    }

    printf("Enter the filename (max 100 chars): ");

    const int filenameLength = 101;

    char filename[filenameLength];

    scanf_s("%s", filename, filenameLength);

    printf("You entered: %s\n", filename);

    FILE* file;
    fopen_s(&file, filename, "w+");

    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", values[i]);
    }

    fclose(file);

    fopen_s(&file, filename, "r");

    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    int currentNumber, sum = 0;
    while (fscanf_s(file, "%d ", &currentNumber) == 1) {
        sum += currentNumber;
    }

    fclose(file);

    float average;
    if (n > 0) {
        average = (float)sum / n;
        printf("Avg: %.2f\n", average);
    } else {
        printf("No values to calculate average. Nothing will be appended to the file.\n");

        return 0;
    }

    fopen_s(&file, filename, "a");

    if (file == NULL) {
        printf("Error opening the file for appending.\n");
        return 1;
    }

    fprintf(file, "Avg: %.2f\n", average);

    fclose(file);

    printf("Average value appended to the file.\n");

    return 0;
}