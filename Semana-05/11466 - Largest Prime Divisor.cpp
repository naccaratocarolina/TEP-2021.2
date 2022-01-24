#include <stdio.h>
#include <math.h>

const int N = 10000000;
unsigned mark[(N>>5)+1];
int primo[670000], pt = 0;

int getter (int x) {
    return mark[x>>5]>>(x&31)&1;
}

void setter (int x) {
    mark[x>>5] |= 1<<(x&31);
}

void geraPrimo () {
    register int i, j;
    int sqr = N;
    setter(0), setter(1);

    for(i = 2; i <= sqr; i++) {
        if(!getter(i)) {
            primo[pt++] = i;
            for(j = i+i; j <= N; j += i)
                setter(j);
        }
    }
}

void calcula (long long n) {
    int i, cnt = 0;
    long long pre = n, ans = -1;

    for(i = 0; primo[i] <= sqrt(n) && i < pt; i++) {
        if(n%primo[i] == 0) {
            ans = primo[i];
            cnt++;
            while(n%primo[i] == 0)
                n /= primo[i];
        }
    }

    if(n != 1)
        ans = n, cnt++;

    if(cnt <= 1)
        ans = -1;

    printf("%lld\n", ans);
}

int main () {
    geraPrimo();
    long long n;

    while(scanf("%lld", &n) == 1 && n) {
        if(n < 0)   n *= -1;
        
        if(n <= N && getter(n) == 0)
            puts("-1");
        
        else
            calcula(n);
    }

    return 0;
}


