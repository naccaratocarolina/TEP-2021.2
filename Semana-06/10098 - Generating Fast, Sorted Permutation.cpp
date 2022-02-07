#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  while (N--) {
    string palavra;
    cin >> palavra;
    sort(palavra.begin(), palavra.end());

    do {
      cout << palavra << endl;
    } while (next_permutation(palavra.begin(), palavra.end()));
    
    cout << endl;	   
  }

  return 0;
}
