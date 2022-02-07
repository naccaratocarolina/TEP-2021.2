#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int cidade[1000];

struct noh { 
  int x, y; 
} Noh[1000];

struct aresta { 
	int x, y;
	double w;
	bool operator<(struct aresta &a) {  return w < a.w; }
} Aresta[499500];

inline int getRaiz(int a) {
	if (cidade[a] == a) { return a; }
	else { return cidade[a] = getRaiz(cidade[a]); }
}

int main (void) {

	ios::sync_with_stdio(false);

	int T, n, r;

	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> n >> r;
		
		for (int j = 0; j < n; ++j) { 
			cidade[j] = j;
			cin >> Noh[j].x >> Noh[j].y;
		}

		int l = 0, estado = 1;
		double estrada = 0, trilho = 0;

		for (int j = 0; j < n; ++j) {
			for (int k = j + 1; k < n; ++k, ++l) {
				Aresta[l].x = j, Aresta[l].y = k;
				Aresta[l].w = sqrt(pow(Noh[j].x - Noh[k].x, 2.0) + pow(Noh[j].y - Noh[k].y, 2.0));
			}
		}
		
		sort(Aresta, Aresta + l);

		for (int j = 0; j < l; ++j) {
			Aresta[j].x = getRaiz(Aresta[j].x);
			Aresta[j].y = getRaiz(Aresta[j].y);

			if (Aresta[j].x != Aresta[j].y) {
				if (Aresta[j].w <= r) { estrada += Aresta[j].w; }
				else { ++estado, trilho += Aresta[j].w; }
				cidade[Aresta[j].y] = Aresta[j].x;
			}
		}

		cout << "Case #" << i << ": " << estado << " "
			 << (int)(estrada + 0.5) << " " << (int)(trilho + 0.5) << endl;
	}

	return 0;
}
