#include <stdio.h>
#include <stdbool.h>

int main() {
    int b = 5; 
    int a = b + 5;
    char dataArray[b];
    char array2[a];
    bool limit = false;
    bool getOut = false;
    
    int i = 0;
    while (i != -1) {
        if (i >= b) {
            printf("Limit Exceeded\n");
            limit = true;

            // Copy dataArray to array2
            for (int j = 0; j < b; j++) {
                array2[j] = dataArray[j];
            }
        }

        if (!limit) {
            // Get input for dataArray until it reaches its limit
            printf("Enter a character for dataArray[%d]: ", i);
            scanf(" %c", &dataArray[i]);
        } else {
            // Get input for array2 after limit is reached
            if (i < a) {
                printf("Enter a character for array2[%d]: ", i);
                scanf(" %c", &array2[i]);
            } else {
                printf("Program finished\n");
                getOut = true;
                break;
            }
        }

        i++; // Increment index for both arrays
    }

    // Output the final content of array2
    printf("\nFinal content of array2:\n");
    for (int t = 0; t < a; t++) {
        printf("%c\n", array2[t]);
    }

    return 0;
}
