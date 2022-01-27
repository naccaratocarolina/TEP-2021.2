#include <cstdio>
#include <iostream>

using namespace std;

int pai[30000];
int contAmigos[30000]; // vetor do tamanho dos grupos de amigos
int maior;

int Find (int a) {
  if (pai[a] != a) pai[a] = Find(pai[a]);
  return pai[a];
}

void Union (int &a, int &b) {
  if (Find(a) == Find(b)) return;

  int tam = contAmigos[Find(a)] += contAmigos[Find(b)];
  maior = max(tam, maior);
  pai[Find(b)] = Find(a);
}

int main (void) {
  int aux, N, M, a, b;

  scanf("%d", &aux);

  while (aux--) {
    scanf("%d %d", &N, &M);
    
    maior = 1;

    for (int i=0; i<N; i++) {
      contAmigos[i] = 1;
      pai[i] = 1;
    }

    for (int i=0; i<M; i++) {
      scanf("%d %d", &a, &b);
      a--; b--;
      Union(a, b);
    }

    printf("%d\n", maior);
  }

  return 0;
}
