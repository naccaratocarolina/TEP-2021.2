#include <cstdio>
#include<bits/stdc++.h>

using namespace std;

const int MAX = 201;

vector<int> arestas[MAX];
int controle[MAX];

void marca (int agora) {
  controle[agora] = 1;

  for (int i=0; i<arestas[agora].size(); i++)
    if (!controle[arestas[agora][i]]) 
      marca(arestas[agora][i]);
}

int main (void) {
  int N, R;
  int x, y;
  int i, j, k;

  while (~scanf("%d %d", &N, &R)) {
    if (!R) {
      printf("Not Possible\n");
      continue;
    }
    
    memset(controle, 0, sizeof(controle));

    for (i=0; i<N; i++)
      arestas[i].clear();

    for (i=0; i<R; i++) {
      scanf("%d%d", &x, &y);
      arestas[x].push_back(y);
      arestas[y].push_back(x);
    }

    for (i=0; i<N; i++) {
      if (arestas[i].size()) {
        marca(i);

        for (j=0; j<N; j++) {
          if (!controle[j] && arestas[j].size() || arestas[j].size() %2) {
            printf("Not Possible\n");
            break;
          }
        }

        if (j >= N) printf("Possible\n");
        break;
      }
    }
  }

  return 0;
}
