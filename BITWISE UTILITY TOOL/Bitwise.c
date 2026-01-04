#include <stdio.h>
#include <stdlib.h>

/**
 * Helper function to print a number in binary format.
 * This helps the user visualize the bitwise operations.
 */
void printBinary(int n) {
    printf("Binary: ");
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
        
        // Add a space every 8 bits for readability
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int choice;
    int num1, num2, result;

    printf("====================================\n");
    printf("       BITWISE UTILITY TOOL         \n");
    printf("====================================\n");

    while (1) {
        // Step 1: Display a menu showing bitwise operation options
        printf("\nSelect a Bitwise Operation:\n");
        printf("1. AND (&)\n");
        printf("2. OR (|)\n");
        printf("3. XOR (^)\n");
        printf("4. Left Shift (<<)\n");
        printf("5. Right Shift (>>)\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

        // Step 2: Ask the user to choose an operation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        if (choice == 6) {
            printf("Exiting Bitwise Utility Tool. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Error: Invalid choice. Please select between 1 and 6.\n");
            continue;
        }

        // Step 3 & 4: Ask for integers and read them
        if (choice == 4 || choice == 5) {
            printf("Enter the integer to shift: ");
            scanf("%d", &num1);
            printf("Enter the shift count: ");
            scanf("%d", &num2);
        } else {
            printf("Enter the first integer: ");
            scanf("%d", &num1);
            printf("Enter the second integer: ");
            scanf("%d", &num2);
        }

        // Step 5: Switch-case for operation matching
        switch (choice) {
            case 1:
                // Step 6: AND operation
                result = num1 & num2;
                printf("\nResult: %d & %d = %d\n", num1, num2, result);
                break;

            case 2:
                // Step 7: OR operation
                result = num1 | num2;
                printf("\nResult: %d | %d = %d\n", num1, num2, result);
                break;

            case 3:
                // Step 8: XOR operation
                result = num1 ^ num2;
                printf("\nResult: %d ^ %d = %d\n", num1, num2, result);
                break;

            case 4:
                // Step 9: Left Shift
                result = num1 << num2;
                printf("\nResult: %d << %d = %d\n", num1, num2, result);
                break;

            case 5:
                // Step 10: Right Shift
                result = num1 >> num2;
                printf("\nResult: %d >> %d = %d\n", num1, num2, result);
                break;

            default:
                printf("Unexpected Error.\n");
                continue;
        }

        // Displaying the binary representation for better understanding
        printBinary(result);
        printf("------------------------------------\n");
    }

    return 0;
}