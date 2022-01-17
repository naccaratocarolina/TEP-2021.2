#include <stdio.h>

#define MAX 1000000000
int primos[MAX], cnt = 0;

void crivo () {
  int f[MAX] = {};

  for (int i=2; i<MAX; i++) {
    if (f[i] == 0) {
      primos[cnt++] = i;
      for (int j=i+i; j<MAX; j+=i)
        primos[j] = 1;
    }
  }
}

int main (void) {
  crivo();
  int n, m;

  while (scanf("%d %d", &n, &m) == 2) {
    for (int i=0; i<cnt && primos[i]*primos[i] <= m; i++) {
      if (m % primos[i] == 0) {
        int k = 0;
        while (m % primos[i] == 0) {
          k++;
          m /= primos[i];
        }

        long long tmp = primos[i];
        int l = 0;
        while (tmp <= n) {
          l += n/tmp;
          tmp *= primos[i];
        }
        if (l < k) {
          printf("%d does not divide %d!\n", m, n);
          break;
        }
      }
    }
    if (m != 1) if (n < m) {
      printf("%d does not divide %d!\n", m, n);
      break;
    }
    
    printf("%d divides %d!\n", m, n);
  }

  return 0;
}
