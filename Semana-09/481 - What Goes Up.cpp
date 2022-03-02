#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;

void imprime (const vector<int> &seq, const vector<int> &v, int pos) {
  if (pos == -1) 
    return;
  imprime(seq, v, v[pos]);
  printf("%d\n", seq[pos]);
}

int main (void) {
  int n;

  while (scanf("%d", &n) != EOF) 
    seq.push_back(n);

  vector<int> menores(seq.size());
  vector<int> menores_id(seq.size());
  vector<int> v(seq.size());

  int finalDaLis = 0, cont = 0;

  for (int i=0; i<seq.size(); ++i) {
    size_t pos = lower_bound(menores.begin(), menores.begin() + cont, seq[i]) - menores.begin();
    menores[pos] = seq[i];
    menores_id[pos] = i;
    v[i] = pos ? menores_id[pos - 1] : 1;

    if (pos == cont) {
      ++cont;
      finalDaLis = i;
    }
  }

  printf("%d\n-\n", cont);
  imprime(seq, v, finalDaLis) ;

  return 0;
}
