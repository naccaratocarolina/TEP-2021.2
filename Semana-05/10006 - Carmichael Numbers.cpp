#include <stdio.h>
#include <stdlib.h>

char primos[65001] = {};

void marcaPrimos() {
	int i, j;

	for (i = 2; i < 65000; i++) {
		if (primos[i] == 0) {
			for (j = 2; i*j < 65000; j++)
				primos[i*j] = 1;
		}
	}
}

long long modulo (long long x, long long y, long long m) {
	long long tmp = x, ans = 1;
	while (y) {
		if (y & 1) {
			ans *= tmp;
			ans %= m;
		}

		tmp = tmp * tmp, tmp %= m;
		y >>= 1;
	}
	return ans;
}

int verifica (int n) {
	int i;
	for(i = 2; i <= n-1; i++) {
		if(modulo(i, n, n) != i)
			return 0;
	}
	return 1;
}

int main () {
	marcaPrimos();
	int n;

	while (scanf("%d", &n) == 1 && n) {
		if (primos[n] == 1 && verifica(n) == 1)
			printf("The number %d is a Carmichael number.\n", n);

		else
			printf("%d is normal.\n", n);
	}

    return 0;
}
