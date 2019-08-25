#include <bits/stdc++.h>
using namespace std;

main() {
  string s;
  cin >> s;
  string w;
  for(char c : s) {
    if(c >= '0' && c <= '9') w.push_back(c);
    else break;
  }
  if(w.empty()) cout << "-1\n";
  else cout << w << endl;
}