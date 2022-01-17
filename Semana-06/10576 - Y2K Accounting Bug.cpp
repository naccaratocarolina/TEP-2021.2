#include <stdio.h>

int main (void) {
  int e, d; // excedente, defict
  
  while (scanf("%d %d", &e, &d) == 2) {
    int excedente_anual = -1, ano;
    int i, j;

    for (ano = (1 << 12) - 1; ano >= 0; ano--) {
      int total = 0, aux = 1;
      for (i=0; i<12; i++) {
        if ((ano >> i) & 1) total += e;
        else total -= d;

        if (i < 8) {
          int tmp = 0;
          for (j=i; i<i+5; j++)
            if ((ano >> j) & 1) tmp += e;
            else tmp -= d;
          if (tmp >= 0) aux = 0;
        }
      }
      if (aux && excedente_anual < total)
        excedente_anual = total;
    }

    if (excedente_anual < 0) puts("Deficit");
    else printf("%d\n", excedente_anual);
  }

  return 0;
}
