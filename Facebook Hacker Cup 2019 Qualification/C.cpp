#include <bits/stdc++.h>
using namespace std;

string s;
int idx = 0;

int getVal() {
  if(s[idx] == '(') {
    idx++;
    char a = getVal();
    char op = s[idx++];
    char b = getVal();
    idx++;
    if(op == '|') {
      if(a == '1' || b == '1') return '1';
      if(a == '0') return b;
      if(b == '0') return a;
      if(a == b) return a;
      return '1';
    } else if(op == '&') {
      if(a == '0' || b == '0') return '0';
      if(a == '1') return b;
      if(b == '1') return a;
      if(a == b) return a;
      return '0';
    } else {
      if(a == '0') return b;
      if(b == '0') return a;
      if(a == b) return '0';
      if(a == '1' && b == 'x') return 'X';
      if(a == '1' && b == 'X') return 'x';
      if(b == '1' && a == 'x') return 'X';
      if(b == '1' && a == 'X') return 'x';
      return '1';
    }
  } else {
    return s[idx++];
  }
}

int main() {
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    cin >> s;
    idx = 0;
    char c = getVal();
    cout << "Case #" << T << ": ";
    if(c == '1' || c == '0') cout << 0 << '\n';
    else cout << 1 << '\n';
  }
}