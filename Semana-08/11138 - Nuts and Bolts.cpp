#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vetor;

int Bolts, Nuts, result, f, s, t, INF = 2000000;
int g[1004][1004];
vetor p;

void aumentar (int valor, int minArestas) {
    if (valor == s) {
        f = minArestas;
        return;
    } 

    else if (p[valor] != -1) {
        aumentar(p[valor], min(minArestas, g[p[valor]][valor]));
        g[p[valor]][valor] -= f; g[valor][p[valor]] += f;
    }
}

int main() {
    int N;
    cin >> N;
    for (int casos = 1; casos <= N; casos++) {
        cin >> Bolts >> Nuts;
        for (int i = 0; i < Bolts+Nuts+2; i++)
            for (int j = 0; j < Bolts+Nuts+2; j++)
                g[i][j] = 0;

        for (int i = 1; i <= Bolts; i++)
            for (int j = 1; j <= Nuts; j++)
                cin >> g[i][j+Bolts];

        for (int i = 1; i <= Bolts; i++) g[0][i] = 1;
        for (int i = 1; i <= Nuts; i++) g[i+Bolts][Bolts+Nuts+1] = 1;

        s = 0, t = Bolts+Nuts+1;
        result = 0;
        while (true) {
            f = 0;
            vetor dist(Bolts+Nuts+2, INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(Bolts+Nuts+2, -1);
            
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < Bolts+Nuts+2; v++) {
                    if (g[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }

            aumentar(t, INF);
            if (f == 0) break;
            result += f;
         }

         printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", casos, result);
    }

    return 0;
}
