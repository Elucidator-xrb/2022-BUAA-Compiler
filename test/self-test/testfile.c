#include "selfio.h"

const int n = 15;   // constDel
const int a1 = 1, a2 = 2;
const int d1 = 10, d2 = 100, d3 = 1000;
int m;              /* VarDecl */
int b1 = 123, b2;
int c1, c2, c3;

int getval() {
    return 1;
}

int foo(int n) {
    return n;
}

int add(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

void put() {
    printf("hello");
    return;
}

int main() {
    printf("20376115\n");
    put();
    printf("a1: %d, a2: %d\n", a1, a2);
    printf("m: %d b2: %d\n", m, b2);
    // Lval = Exp, cover all Exp
    b1 = n * 2 - n / 2 + n % 2 * -(3) * +8 % b1 * getval() / add(1, 1) * foo(b1);

    printf("b: %d\n", b1);

    int a1;
    a1 = getint();
    printf("a1: %d\n", a1);

    ;;;;;;;;;;;;;;;;;;;;;;;

    printf("sum: %d\n", sum(1, 2, 3));

    {
        int a1 = 3;
        printf("a1: %d\n", a1);
        {

        }
    }
    int i = 0, j = 0;
    /*while (!i) {
        printf("i: %d\n", i);
        j = j + 1;
        if (j < 3)
            if (j > 1)
                printf("j: %d > 1\n", j);
            else
                continue;

        if (i != i == i <= -1) {
            printf("123456\n");
        }

        if (j >= 4) { break; }
    }*/


    return 0;
}

