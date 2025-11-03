//2D_array
/*
Name: Arnold Siere
Registration No: PA106/G/28835/25
Description :2D_array
*/
#include <stdio.h>

int main(void) {
    // i. Define an array data structure
    // An array is a collection of elements of the same data type stored in contiguous memory locations.

    // ii. Declare and initialize a 2D array
    int scores[4][2] = {
        {65, 92},
        {84, 72},
        {35, 70},
        {59, 67}
    };

    // iii. Print the elements using nested for loops
    int i, j; // Declare loop variables here for older compilers
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n"); // Move to next row
    }

    return 0;
}