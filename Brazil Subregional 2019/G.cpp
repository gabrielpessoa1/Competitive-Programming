#include <bits/stdc++.h>
using namespace std;

const double inf = 1e100;

const int ms = 105;

double u[ms], v[ms];
int p[ms], way[ms];
double minv[ms];
bool used[ms];

pair<vector<int>, double> solve(const vector<vector<double>> &matrix) {
  int n = matrix.size();
  if (n == 0) return {vector<int>(), 0};
  for(int i = 1; i <= n; i++) {
    for(int i = 0; i <= n; i++) minv[i] = inf;
    memset(way, 0, (n+1) * sizeof(int));
    for(int j = 0; j <= n; j++) used[j] = false;
    p[0] = i;
    int k0 = 0;
    do {
      used[k0] = true;
      int i0 = p[k0], k1;
      double delta = inf;
      for(int j = 1; j <= n; j++) {
        if(!used[j]) {
          double cur = matrix[i0-1][j-1] - u[i0] - v[j];
          if(cur < minv[j]) {
            minv[j] = cur;
            way[j] = k0;
          }
          if(minv[j] < delta) {
            delta = minv[j];
            k1 = j;
          }
        }
      }
      for(int j = 0; j <= n; j++) {
        if(used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      k0 = k1;
    } while (p[k0] != 0);
    do {
      int k1 = way[k0];
      p[k0] = p[k1];
      k0 = k1;
    } while (k0 != 0);
  }
  vector<int> ans(n, -1);
  for(int j = 1; j <= n; j++) {
    if(p[j] == 0) continue;
    ans[p[j] - 1] = j-1;
  }
  return {ans, -v[0]};
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  vector<vector<double>> ans;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    ans.push_back(vector<double>(n));
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      ans[i][j] = -log(x);
    }
  }
  vector<int> res = solve(ans).first;
  vector<int> trueRes(n);
  for(int i = 0; i < n; i++) {
    trueRes[res[i]] = i+1;
  }
  for(int i = 0; i < n; i++) {
    cout << trueRes[i] << " \n"[i == n-1];
  }
}