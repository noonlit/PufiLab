/*
Write a program that reads from the keyboard a single character and an integer value n. 
Generate a text file that will contain n lines and on each line write the character n times, n being read from the keyboard.
*/

#include <iostream>

int main()
{
    char c;
    printf("Enter the character value: ");
    scanf_s("%c", &c);

    int n;

    printf("Enter the integer value: ");
    scanf_s("%d", &n);

    FILE* file;
    fopen_s(&file, "problem_4.txt", "w+");

    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%c", c);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("File generated successfully.\n");

    return 0;
}