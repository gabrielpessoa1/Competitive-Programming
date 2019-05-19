// Benelux Algorithm Programming Contest preliminaries 2018
// B - Bee Problem
// https://open.kattis.com/problems/beeproblem

#include <bits/stdc++.h>
using namespace std;

const int ms = 3005;

int h;
int n, m;
string s[ms];
int vis[ms][ms];
vector<int> comps;
int dx[6] = {0, 0, 1, -1, 1, -1};
int dy[6] = {2, -2, 1, 1, -1, -1};

int dfs(int i, int j) {
  if(i < 0 || i >= n || j < 0 || j >= s[i].size() || s[i][j] != '.' || vis[i][j]) return 0;
  vis[i][j] = 1;
  int ans = 1;
  for(int d = 0; d < 6; d++) {
    ans += dfs(i + dx[d], j + dy[d]);
  }
  return ans;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> h >> n >> m;
  getline(cin, s[0]);
  for(int i = 0; i < n; i++) {
    getline(cin, s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < s[i].size(); j++) {
      if(s[i][j] == '.' && !vis[i][j]) comps.push_back(dfs(i, j));
    }
  }
  sort(comps.begin(), comps.end());
  reverse(comps.begin(), comps.end());
  int ans = 0;
  for(int u : comps) {
    if(h > 0) {
      h -= u;
      ans++;
    }
  }
  cout << ans << endl;
}