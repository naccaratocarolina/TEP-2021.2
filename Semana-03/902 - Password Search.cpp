#include <iostream>
#include <map>

using namespace std;

int main (void) {
  int N;
  string str, substr;

  while (cin >> N >> str) {
    map<string, int> m;
    int len = str.length();

    for (int i=0; i<(len-N+1); i++) {
      substr.assign(str, i, N);
      m[substr]++;
    }

    int max = 0;
    for (map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
      if (i->second > max) {
        max = i->second;
        str = i->first;
      }
    }
    cout << str << endl;
  }

  return 0;
}
