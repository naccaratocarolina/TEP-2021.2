#include <iostream>

using namespace std;

unsigned long num1, num2;

int main (void) {
  cin >> num1 >> num2;

  while (num1 != 0 || num2 != 0) {
    int cont = 0;
    bool fim = false;

    while (num1 || num2) {
      int somaAtual = num1 % 10 + num2 % 10;

      if (fim) {
        ++somaAtual;
        fim = false;
      }

      if (somaAtual >= 10) {
        ++cont;
        fim = true;
      }

      num1 /= 10;
      num2 /= 10;
    }

    if (!cont)
      printf("No carry operation.\n");
    else if (cont > 1)
      printf("%d carry operations.\n", cont);
    else
      printf("%d carry operation.\n", cont);
  }

  return 0;
}
