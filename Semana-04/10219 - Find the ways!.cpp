#include <iostream>
#include <cmath>

using namespace std;

int main (void) {
  unsigned long long n, k, i;
  long double soma;
  
  while (cin >> n >> k) {
    soma = 0;

    for (i=n-k+1; i<=n; i++)
      soma += log10(i);
    for (i=k; i>=1; i--)
      soma -= log10(i);

    soma = (int) floor(soma) + 1;
    printf("%d\n", soma);
  }

  return 0;
}
