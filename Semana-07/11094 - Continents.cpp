#include <iostream>
#include <string>

using namespace std;

int regiao = 0, M, N;
char mapa[20][20], terra;
bool foiVisitado[20][20];

void DFS(int x, int y) {

	if (y == N) { y = 0; }
	else if (y == -1) { y = N - 1; }
	
	if (x < 0 || x >= M || foiVisitado[x][y] == true || mapa[x][y] != terra) { return; }
	else {
		++regiao, foiVisitado[x][y] = true;
		DFS(x - 1, y);
		DFS(x, y + 1);
		DFS(x, y - 1);
		DFS(x + 1, y);
	}
}

int main (void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int X, Y;
	string linha;

	while (cin >> M >> N) {

		cin.ignore(1024, '\n');

		int maior = 0;

		for (int i = 0; i < M; ++i) {

			getline(cin, linha);

			for (int j = 0; j < N; ++j) {

				mapa[i][j] = linha[j];
				foiVisitado[i][j] = false;
			}
		}

		cin >> X >> Y;
		terra = mapa[X][Y], DFS(X, Y);

		for (int i = 0; i < M; ++i) {

			for (int j = 0; j < N; ++j) {

				if (mapa[i][j] == terra && foiVisitado[i][j] == false) {
					regiao = 0, DFS(i, j);
					if (regiao > maior) { maior = regiao; }
				}
			}
		}

		cout << maior << endl;		
	}

	return 0;
}
