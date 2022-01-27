#include <bits/stdc++.h>

using namespace std;

int colunas[8];
int visitado[8];

bool marca (int i, int k) {
  for (int j=1; j<i; j++)
    if (abs(j - i) == abs(colunas[j] - k))
      return false;

  return true;
}

int dfs (int k) {
	if (k == 8) return 0;

	int jogadas = 8;
	for (int i = 0; i < 8; ++i) {
		if (!marca(i, k)) {
			colunas[k] = i;
			jogadas = min(jogadas, visitado[k] == i ? dfs(k + 1) : (dfs(k + 1)) + 1);
		}
	}

	return jogadas;
}

int main (void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int caso = 0;
	while (cin >> visitado[0]) {
		colunas[0] = --visitado[0];
		
    for (int i = 1; i < 8; ++i) {
			cin >> visitado[i];
			
			colunas[i] = --visitado[i];
		}
	  
    printf("Case %d: %d\n", ++caso, dfs(0));
	}

	return 0;
}
