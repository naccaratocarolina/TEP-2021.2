#include <stdio.h>
#include <math.h>

int main (void) {
  long n;

  while (scanf("%ld", &n) == 1 && n > 0) {
    long raiz = (long) sqrt(n);
    if (raiz * raiz == n) puts("yes");
    else puts("no");
  }

  return 0;
}
