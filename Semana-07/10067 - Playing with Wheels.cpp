#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define N 10000

inline int entrada (void) {
  int n = 0, k = 0;
  char ch;

  while (k < 4) {
    ch = getchar();
    if (ch >= '0' && ch <= '9') {
      n = n * 10 + ch - '0';
      ++k;
    }
  }

  return n;
}

int main (void) {
  int T;
  bool visitado[N] = {};
  int passo[N] = {};
  scanf("%d", &T);

  while (T--) {
    int s, t, n;
    s = entrada();
    t = entrada();
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
      visitado[entrada()] = true;

    if (s == t) puts("0");

    else if (visitado[t]) puts("-1");

    else {
      // BFS
      queue<int> Q;
      Q.push(s);
      visitado[s] = true;

      while (!Q.empty()) {
        int ultimo = Q.front();
        Q.pop();

        for (int k = 1000, cpy = ultimo; k; k /= 10) {
          int tmp = (ultimo / k) % 10; 

          if (tmp < 9) ultimo += k;

          else ultimo -= 9 * k;

          if (!visitado[ultimo]) {
            Q.push(ultimo);
            passo[ultimo] = passo[cpy] + 1;
            visitado[ultimo] = true;
          }

          if (ultimo == t) break;

          ultimo = cpy;

          if (tmp) ultimo -= k;

          else ultimo += 9 * k;

          if (!visitado[ultimo]) {
            Q.push(ultimo);
            passo[ultimo] = passo[cpy] + 1;
            visitado[ultimo] = true;
          }

          if (ultimo == t) break;

          ultimo = cpy;
        }
      }

      printf("%d\n", passo[t] ? passo[t] : -1);
    }

    memset(visitado, false, sizeof visitado);
    memset(passo, 0, sizeof passo);
  }

  return 0;
}
