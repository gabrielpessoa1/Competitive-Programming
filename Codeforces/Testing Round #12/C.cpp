#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int n, k;
long long bit[15][ms];
int arr[ms];

void update(int i, int idx, int v) {
  while(idx <= n) {
    bit[i][idx] += v;
    idx += idx & -idx;
  }
}

long long query(int i, int idx) {
  long long ans = 0;
  while(idx > 0) {
    ans += bit[i][idx];
    idx -= idx & -idx;
  }
  return ans;
}

int main() {
  cin >> n >> k;
  long long ans = 0;
  update(0, 1, 1);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    ans += query(k, arr[i]);
    for(int j = k; j > 0; j--) {
      update(j, arr[i], query(j-1, arr[i]));
    }
  }
  cout << ans << '\n';
}