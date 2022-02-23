#include <iostream>
#include <cstring>

using namespace std;

int w[10][1001]; // windstrength
int m[10][1001]; // memorando
int X; // voar ate X

int calculaCombustivel (int altitude, int distancia) {
  if (altitude < 0 || altitude > 9 || distancia > X)
    return 1001;

  if (distancia == X) {
    if (altitude == 0) return 0;
    else return 1001;
  }

  if (m[altitude][distancia] != -1) return m[altitude][distancia];
  
  return min(
      60 - w[altitude][distancia] + calculaCombustivel(altitude + 1, distancia + 1), 
      min(30 - w[altitude][distancia] + calculaCombustivel(altitude, distancia + 1), 
      20 - w[altitude][distancia] + calculaCombustivel(altitude - 1, distancia + 1)));
}

int main (void) {
  int tc; // test cases
  cin >> tc;

  while (tc--) {
    cin >> X;
    X /= 100;

    for (int altitude=9; altitude>=0; --altitude) {
      for (int distancia=0; distancia<X; ++distancia)
        cin >> w[altitude][distancia];
    }

    memset(m, -1, sizeof(m));

    int resp = calculaCombustivel(0, 0);
    cout << resp << "\n\n";
  }

  return 0;
}
