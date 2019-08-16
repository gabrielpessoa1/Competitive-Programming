#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void get(string &s) {
  string p = "";
  string v = "";
  string k;
  cin >> k;
  for(char c : k) {
    if(c == ',' || c == ';') {
      reverse(p.begin(), p.end());
      cout << s << p << ' ' << v << ';' << '\n';
      if(c == ',') get(s);
    } else if(c == '*' || c == '[' || c == ']' || c == '&') {
      if(c != '[') p.push_back(c);
      if(c == ']') p.push_back('[');
    } else {
      v.push_back(c);
    }
  }
}
 
main() {
  #ifdef ONLINE_JUDGE
  freopen("isharp.in", "r", stdin);
  freopen("isharp.out", "w", stdout);
  #endif
  string s;
  cin >> s;
  get(s);
}