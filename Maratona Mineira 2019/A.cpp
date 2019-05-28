#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6+5;

vector<int> segX[ms];
vector<int> segY[ms];

int get(vector<int> &v) {
  sort(v.begin(), v.end());
  int ans = 0;
  for(int i = 0; i < v.size() - 1; i++) {
    int k = v[i+1] - v[i] - 2;
    ans += (k+1)*k/2;
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    segX[i] = {0, n+1};
    segY[i] = {0, n+1};
  }
  int ans = n * n - q;
  for(int i = 0; i < q; i++) {
      int x, y;
      cin >> x >> y;
      segX[x].push_back(y);
      segY[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    ans += get(segX[i]);
    ans += get(segY[i]);
  }
  cout << ans << '\n';
}