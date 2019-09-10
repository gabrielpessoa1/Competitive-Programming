#include <bits/stdc++.h>
using namespace std;

int lim = 1e8;

bool equal(string &a, string &b) {
  if(a.size() != b.size()) return false;
  if(b[0] != a[a.size()-1]) return false;
  for(int i = 1; i < a.size(); i++) {
    if(b[i] != a[i-1]) return false;
  }
  return true;
}

main() {
  double x;
  cin >> x;
  int a = round(x*1e4);
  int b = 1e4;
  int gc = __gcd(a, b);
  a /= gc; b /= gc;
  if(a == 1) {
    for(int i = 1; i <= 8; i++) {
      for(int j = 1; j <= 9; j++) {
        for(int k = 0; k < i; k++) {
          cout << j;
        }
        cout << '\n';
      }
    }
  } else if(a == 2) {
    cout << "No solution\n";
  } else if(a == 3) {
    if(b == 1) {
      cout << 142857 << '\n';
      cout << 285714 << '\n';
    } else {
      cout << "No solution\n";
    }
  } else if(a == 4) {
    cout << "No solution\n";
  } else {
    int j = b;
    bool found = 0;
    for(int i = a; i < lim; i += a) {
      string x = to_string(i);
      string y = to_string(j);
      if(equal(x, y)) {
        cout << y << '\n';
        found = 1;
      }
      j += b;
    }
    if(!found) cout << "No solution\n";
  }
}