#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main (void) {
  string a, b;
  while (getline(cin, a), getline(cin, b)) {
    int a_cont[26], b_cont[26];
    string s = "";

    for (int i='a'; i<='z'; ++i) 
      a_cont[i] = b_cont[i] = 0;

    for (int i=0; i<a.size(); ++i)
      ++a_cont[a[i]];

    for (int i=0; i<b.size(); ++i)
      ++b_cont[b[i]];

    for (int i='a'; i<='z'; ++i) {
      for (int i=min(a_cont[i], b_cont[i])-1; i>=0; --i)
        putchar('a' + i);
    }
    putchar('\n');
  }

  return 0;
}
