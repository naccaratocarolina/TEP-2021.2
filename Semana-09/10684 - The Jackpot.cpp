#include <iostream>

using namespace std;

int main (void) {
  int N, aposta;

  while (scanf("%d", &N), N) {
    int seqMaxima = 0, ganho = 0;

    for (int i=0; i<N; i++) {
      scanf("%d", &aposta);
      
      ganho += aposta;

      if (ganho < 0) ganho = 0;
      if (ganho > seqMaxima) seqMaxima = ganho;
    }

    if (seqMaxima) printf("The maximum winning streak is %d.\n", seqMaxima);
    else printf("Losing streak.\n");
  }

  return 0;
}
