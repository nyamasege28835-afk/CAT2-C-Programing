//Processor integer
/*
Name: Arnold Siere
Registration No: PA106/G/28835/25
Description :Processor integer
*/
#include <stdio.h>
#include <stdlib.h>

// Function to write 10 integers to "input.txt"
void writeInputFile() {
    FILE *fptr;
    int numbers[10];

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(fptr, "%d\n", numbers[i]);
    }

    fclose(fptr);
    printf("Data successfully written to input.txt\n\n");
}

// Function to read from "input.txt" and write sum & average to "output.txt"
void processFiles() {
    FILE *fin, *fout;
    int num, sum = 0, count = 0;
    float avg;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for reading.\n");
        exit(1);
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(fin);
        exit(1);
    }

    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count > 0)
        avg = (float)sum / count;
    else
        avg = 0;

    fprintf(fout, "Sum = %d\nAverage = %.2f\n", sum, avg);

    fclose(fin);
    fclose(fout);
    printf("Results written to output.txt\n\n");
}

// Function to display contents of both files
void displayFiles() {
    FILE *fptr;
    char ch;

    printf("---- Contents of input.txt ----\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt.\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n---- Contents of output.txt ----\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening output.txt.\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);
}

int main() {
    writeInputFile();
    processFiles();
    displayFiles();

    return 0;
}
