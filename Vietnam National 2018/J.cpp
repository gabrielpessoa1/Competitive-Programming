#include <bits/stdc++.h>
using namespace std;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    if(s.size() % 2 == (s[0] == s[s.size()-1])) {
      cout << "Bash\n";
    } else {
      cout << "Chikapu\n";
    }
  }
}