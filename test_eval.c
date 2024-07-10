//
// Created by FRASER on 08/07/2024.
//

#include <stdio.h>
#include "sledeval.h"

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
    int expected[] = {
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
        int result = eval(expressions[i]);
        if (result != expected[i]) {
            printf("Test failed: %s = %d (expected %d)\n", expressions[i], result, expected[i]);
            passed = 0;
        } else {
            printf("Test passed: %s = %d\n", expressions[i], result);
        }
    }

    if (passed) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed.\n");
    }

    return !passed;
}