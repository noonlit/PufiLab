/*
* Write a program that displays the integer elements read from a text file. 
* The filename is entered from the keyboard. 
* The file has to be created in the program in advance.
*/

#include <iostream>

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

    const char* numbers = "1 2 3 4 5 6 7 8 9 10";

    fputs(numbers, file);

    fclose(file);

    fopen_s(&file, filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    while (fscanf_s(file, "%d ", &n) == 1) {
        printf("%d\n", n);
    }
    
    fclose(file);

    return 0;
}
