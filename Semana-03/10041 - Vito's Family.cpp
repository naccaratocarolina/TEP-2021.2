#include <stdio.h>
#include <stdlib.h>

int computaSubtracao (const void *i, const void *j) {
  return *(int *)i - *(int *)j;
}

int main (void) {
  int r, s, parentes[501], i;
  scanf("%d", &r);

  while (r--) {
    scanf("%d", &s);
    for (i=0; i<s; i++)
      scanf("%d", &parentes[i]);

    qsort(parentes, s, sizeof(int), computaSubtracao);
    // Computa a distancia minima
    int min = 0, select = s/2;
    for (i=0; i<s; i++)
      min =+ abs(parentes[select] - parentes[i]);
    printf("%d\n", min);
  }

  return 0;
}
