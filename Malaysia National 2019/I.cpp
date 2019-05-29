#include <bits/stdc++.h>
using namespace std;

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    bool here = false;
    for(char c : s) {
      if(c == '=') here = true;
      else if(here && c != '.') {
        cout << c << endl;
        return 0;
      }
    }
  }
  cout << "You shall pass!!!" << endl;
}