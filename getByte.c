#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x, n;

    scanf("%d %d", &x, &n);

    printf("%d\n", getByte(x, n));

    return 0;
}
