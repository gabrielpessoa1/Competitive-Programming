// VTEX Code Cup 2019
// C - Conveyor Belt Inspection
// https://vtexcc19.kattis.com/problems/vtexcc19.conveyorbeltinspection

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 0x3f3f3f3f;
const int ms = 3005;
const int mod = 1e9+7;

int dx[300], dy[300];
string g[ms];
int cycleSz[ms][ms];
int vis[ms][ms];
int visiting[ms][ms];
int t[ms][ms];
int curT;
int n, m;

int dfs(int i, int j) {
  if(i < 0 || i > n -1 || j < 0 || j > m - 1) return -1;
  if(visiting[i][j]) {
    cycleSz[i][j] = curT - t[i][j];
    return cycleSz[i][j];
  }
  if(vis[i][j]) return -1;
  vis[i][j] = 1;
  visiting[i][j] = 1;
  t[i][j] = curT++;
  int ans = cycleSz[i][j] = -1;
  int temp = dfs(i+dx[g[i][j]], j+dy[g[i][j]]);
  if(~temp) {
    if(cycleSz[i][j] == -1) {
      ans = cycleSz[i][j] = temp;
    }
  }
  visiting[i][j] = 0;
  return ans;
}

int dfs2(int i, int j) {
  if(i < 0 || i > n -1 || j < 0 || j > m - 1) return 0;
  if(~cycleSz[i][j]) return cycleSz[i][j];
  else return cycleSz[i][j] = 1 + dfs2(i+dx[g[i][j]], j+dy[g[i][j]]);
}

main() {
  dx['N'] = -1;
  dx['S'] = 1;
  dy['E'] = 1;
  dy['W'] = -1;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dfs(i, j);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans += dfs2(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}