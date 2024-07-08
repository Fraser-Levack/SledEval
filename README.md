## C Eval function for strings

This is a simple C function that evaluates a string as a mathematical expression. It is a simple implementation of the shunting yard algorithm. It is not a full implementation of the algorithm, but it is enough to evaluate simple expressions.

Could potentially be used to create entire interpreters for simple languages.

### Usage

```c
#include <stdio.h>
#include "sledeval.h"

int main() {
    char *expression = "2 + 2 * 2";
    int result = eval(expression);
    if (result != 6) {
        printf("Test failed: %s = %d (expected 6)\n", expression, result);
        passed = 0;
    } else {
        printf("Test passed: %s = %d\n", expression, result);
    }
    return 0;
}
```

Concept credit to Steve Summit Stack Overflow.

        
