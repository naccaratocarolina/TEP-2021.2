#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct Node {
  long long x;
  string pos;

  bool operator <(const Node &other) const {
    if (pos.size() != other.pos.size())
      return pos.size() < other.pos.size();

    return pos < other.pos;
  }
};

Node nodes[260];

bool parents (const set<string> &allPos) {
  for (set<string>::iterator i = allPos.begin(); i!=allPos.end(); ++i) {
    if (*i != "") {
      string s = i->substr(0, i->size() - 1);
      if (allPos.find(s) == allPos.end())
        return false;
    }
  }

  return true;
}

int main (void) {
  set<string> allPos;
  char firstBracket, comma;

  while (cin >> firstBracket >> nodes[0].x >> comma >> nodes[0].pos) {
    allPos.clear();

    nodes[0].pos = nodes[0].pos.substr(0, nodes[0].pos.size() - 1);
    allPos.insert(nodes[0].pos);

    int pos = 1;
    bool valid = true;

    while (cin >> firstBracket, cin.peek() != ')') {
      cin >> nodes[pos].x >> comma >> nodes[pos].pos;

      nodes[pos].pos = nodes[pos].pos.substr(0, nodes[pos].pos.size() - 1);

      if (allPos.find(nodes[pos].pos)) != allPos.end()
        valid = false;

      allPos.insert(nodes[pos].pos);

      ++pos;
    }

    cin.ignore();

    if (valid && parents(allPos)) {
      sort(nodes, nodes + pos);

      cout << nodes[0].x;
      for (int i=1; i<pos; ++i)
        cout << ' ' << nodes[i].x;
      cout << '\n';
    }

    else 
      cout << "not complete\n";
  }
}
