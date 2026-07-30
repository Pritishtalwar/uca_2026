#include <stdio.h>

/*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(6, 5) = 4
 * Legal ops: ~ |
 */

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Result: %d\n", bitAnd(x, y));

    return 0;
}
