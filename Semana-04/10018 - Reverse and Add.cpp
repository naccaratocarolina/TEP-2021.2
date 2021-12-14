#include <stdio.h>

int main (void) {
  int N; // test cases
  long long P; // number P to compute its palindrome

  while (N--) {
    scanf("%lld", &P);
    int cont = 0;
    long long left, right;
    
    do {
      left = P;
      right = 0;
      while (P) {
        right = right*10 + right%10;
        P /= 10;
      }
      cont++;
      P = left + right;
    } while (left != right);

    printf("%d %lld\n", cont-1, left);
  }

  return 0;
}
