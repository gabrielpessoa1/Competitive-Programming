#include <bits/stdc++.h>
using namespace std;

const int ms = 100;
int vis[ms][ms];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string s[5] = {"NORTH", "WEST", "SOUTH", "EAST", "DONE"};

void solve(int a, int b, int k) {
  if(vis[a][b]) return;
  vis[a][b] = 1;
  if(k != 4) {
    cout << s[k] << endl;
    string inp;
    cin >> inp;
    if(inp[0] == 'B') return;
    k = (k + 2) % 4;
  }
  for(int i = 0; i < 4; i++) {
    if(i == k) continue;
    solve(a+dx[i], b+dy[i], i);
  }
  cout << s[k] << endl;
  if(k != 4) {
    string inp;
    cin >> inp;
    assert(inp[0] == 'E');
  }
}

main() {
  solve(50, 50, 4);
}