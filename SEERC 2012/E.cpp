#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2e5+5;

string s[ms];

int get(int i, int j, int a, int b, int mv) {
  if(a == 1) return j;
  int x = i, y = j;
  if(i <= a/2 && s[mv][1] == 'U') {
    x = a/2 - i + 1;
  } else if(i > a/2) {
    if(s[mv][1] == 'U') {
      x -= a/2;
    } else {
      x = a - i + 1;
    }
  }
  if((i <= a/2 && s[mv][1] == 'U') || (i > a/2 && s[mv][1] == 'D')) {
    y = b - j + 1;
    if(s[mv][0] == 'R') y += b;
  } else if(s[mv][0] == 'L') y += b;
  return get(x, y, a/2, b*2, mv-1);
}

main() {
  #ifdef ONLINE_JUDGE
  freopen("e.in", "r", stdin);
  #endif
  cin.tie(0); ios::sync_with_stdio(0);
  int k = 21, m = 1024;
  for(int i = 0; i < k; i++) cin >> s[i];
  for(int i = 1; i <= m; i++) {
    cout << get(i, 1, (1 << k), 1, k-1) << '\n';
  }
}