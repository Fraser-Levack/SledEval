//
// Created by FRASER on 08/07/2024.
//

#include <stdio.h>
#include "sledeval.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Consume all characters until a newline or EOF
}

int main() {
    // Test expressions
    const char* expressions[] = {
        "1 + 2",
        "2 * (3 + 4)",
        "10 / 2 - 1",
        "-1 + (-2)",
        "3 * (2 - 5 + 3) / 2",
        // more power testing
        "2^3",
        "2^3^2",
        "2 ^ (1 + 1)",
        "2 ^ 0",
        "10 - (1+1 )^ 2"
    };

    // Expected results
    const int expected[] = {
        3,
        14,
        4,
        -3,
        0,
        8,
        64,
        4,
        1,
        6
    };

    int passed = 1;
    for (int i = 0; i < sizeof(expressions) / sizeof(expressions[0]); i++) {
        const int result = eval(expressions[i]);
        if (result != expected[i]) {
            printf("Test failed: %s = %d (expected %d)\n", expressions[i], result, expected[i]);
            passed = 0;
        } else {
            printf("Test passed: %s = %d\n", expressions[i], result);
        }
    }

    if (passed) {
        printf("All tests passed!\n");
        // user testing if all tests passed
        printf("Would you like to test your own expression? (y/n): ");
        char c;
        scanf("%c", &c);
        if (c == 'y') {
            char expr[100];
            printf("Enter your expression: ");
            clear_input_buffer();
            fgets(expr, sizeof(expr), stdin);

            // check if empty and ask again
            while (expr[0] == '\n') {
                printf("No expression was entered. Please try again: ");
                clear_input_buffer();
                fgets(expr, sizeof(expr), stdin);
            }

            printf("Result: %d\n", eval(expr));
        }
    } else {
        printf("Some tests failed.\n");
    }

    return !passed;
}