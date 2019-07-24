#include <bits/stdc++.h>
using namespace std;

const int ms = (1<<18);
const int inf = 2e9+1;

int a[ms];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> subseq = {0};
vector<pair<int, int>> val;
vector<int> cur;
vector<int> ans;
int negSum;

void solve(int p = 0) {
  if(p == (int) val.size()) {
    if(negSum != a[0]) return;
    ans = cur;
    sort(ans.begin(), ans.end());
    cout << ans[0];
    for(int i = 1; i < (int) ans.size(); i++) cout << ' ' << ans[i];
    cout << '\n';
  } else {
    int x = val[p].first, k = val[p].second;
    for(int i = 0; i <= k; i++) {
      if(i < k && x == 0) continue;
      for(int j = 0; j < i; j++) {
        cur.push_back(x);
      }
      for(int j = i; j < k; j++) {
        cur.push_back(-x);
        negSum -= x;
      }
      solve(p+1);
      for(int j = i; j < k; j++) negSum += x;
      for(int j = 0; j < k; j++) cur.pop_back();
    }
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }
  pq.push(inf);
  sort(a, a + (1 << n));
  for(int i = 1; i < (1 << n); i++) {
    int k = a[i] - a[0];
    if(pq.top() == k) {
      pq.pop();
      continue;
    }
    if(!val.empty() && val[val.size()-1].first == k) {
      val[val.size()-1].second++;
    } else {
      val.emplace_back(k, 1);
    }
    int sz = subseq.size();
    for(int j = 0; j < sz; j++) {
      subseq.push_back(subseq[j] + k);
      if(j) pq.push(subseq[j] + k);
    }
  }
  reverse(val.begin(), val.end());
  solve();
}