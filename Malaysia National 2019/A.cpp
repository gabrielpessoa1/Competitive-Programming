#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;

string g[ms];
string ng[ms];

char get(char c) {
  if(c == '.') return c;
  vector<char> v = {'>', 'v', '<', '^'};
  for(int i = 0; i < 4; i++) {
    if(c == v[i]) return v[(i+1)%4];
  }
}

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
    ng[i].resize(n);
  }
  int right = 0;
  for(char c : s) {
    if(c == 'R') right++;
    else right--;
  }
  right = (right + 400) % 4;
  while(right--) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        ng[j][n-1-i] = get(g[i][j]);
      }
    }
    for(int i = 0; i < n; i++) {
      g[i] = ng[i];
    }
  }
  for(int i = 0; i < n; i++) {
    cout << g[i] << '\n';
  }
}