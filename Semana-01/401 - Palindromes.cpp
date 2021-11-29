#include <stdio.h>
#include <string.h>

using namespace std;

int main (void) {
  char entrada[100];

  while (scanf("%s", entrada) == 1) {
    int n = strlen(entrada);
    int i, j;

    char inverso1[] = "A   3  HIL JM O   2TUVWXY5";
    char inverso2[] =  "01SE Z  8 ";

    int palindromo = 0, espelhado = 0;

    for (i=0, j=n-1; i<=j; i++, j--) {
      if (entrada[i] != entrada[j]) palindromo = 1;

      if (entrada[i] >= 'A' && entrada[i] <= 'Z') {
        if (entrada[j] != inverso1[entrada[i] - 'A']) espelhado = 1;

        else {
          if (entrada[j] != inverso2[entrada[i] - '0']) espelhado = 1;
        }  
      }
    }
  
    printf("%s -- is ", entrada);

    if (palindromo) {
      if (espelhado) puts("not a palindrome.");
      else puts("a mirrored string.");
    }

    else {
      if (espelhado) puts("a regular palindrome.");
      else puts("a mirrored palindrome.");
    }
    puts("");
  }
  
  return 0;
}
