#include <bits/stdc++.h>
using namespace std;

int a, b;

int getS(int bm, int k) {
  a = 0; b = 0;
  for(int i = 0; i < k; i++) {
    a += ((bm & (1 << i)) >> i);
    if(a - b > (k-i)/2) return i + 1;
    if(b - a > (k-i-1)/2) return i + 1;
    swap(a, b);
  }
  return k;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    int k;
    cin >> k;
    k += k;
    int p = 0;
    for(int i = 0; i < k; i++) {
      string s;
      cin >> s;
      if(s[0] == 'E') {
        p |= (1 << i);
      }
    }
    int s = getS(p, k);
    int x = a, y = b;
    for(int i = 0; i <= s; i++) {
      int poss = 0;
      for(int j = 0; j < (1 << s); j++) {
        int valid = 1;
        for(int l = 0; l < i; l++) {
          if((j & (1 << l)) != (p & (1 << l))) {
            valid = 0;
          }
        }
        if(valid && getS(j, k) == s && a == x && b == y) poss++;
      }
      if(poss == 1) {
        cout << s << ' ' << i << endl;
        break;
      }
    }
  }
}