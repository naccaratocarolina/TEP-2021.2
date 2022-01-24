#include <stdio.h>
#define maxL (10000000>>5)+1
#define getter(x) (primos[(x)>>5]>>((x)&31)&1)
#define setter(x) (primos[(x)>>5] |= 1<<((x)&31))

int primos[maxL];

void marcaPrimos () {
    register int i, j, k;
    setter(1);
    int n = 10000000;
    for(i = 2; i <= n; i++) {
        if(!getter(i)) {
            for(k = n/i, j = i*k; k >= i; k--, j -= i)
                setter(j);
        }
    }
}

void conjGoldbach (int n) {
    if(n == 4) {
        printf("2 2");
        return;
    }
    static int i;
    for(i = 3; ; i += 2) {
        if(!getter(i) && !getter(n-i)) {
            printf("%d %d", i, n-i);
            return;
        }
    }
}

int main () {
    marcaPrimos();
    int n;

    while (scanf("%d", &n) == 1) {
        if (n < 8) {
            puts("Impossible.");
            continue;
        }
        if (n&1)
            printf("2 3 "), n -= 5;
        else
            printf("2 2 "), n -= 4;
        conjGoldbach(n);
        puts("");
    }
    return 0;
}
