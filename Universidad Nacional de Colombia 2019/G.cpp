#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;

typedef pair<int, int> ii;

int n, k;
int hit;
int a[ms];
int w[ms];
int deg[ms];
priority_queue<ii> pq;

int solve(int x) {
  if(~w[x]) return w[x];
  else if(!a[x]) return 0;
  else return w[x] = solve(a[x]) + 1;
}

main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    deg[a[i]]++;
  }
  memset(w, -1, sizeof w);
  for(int i = 1; i <= n; i++) {
    solve(i);
  }
  for(int i = 1; i <= n; i++) {
    if(deg[i] == 0) pq.push({w[i], i});
  }
  int days = 0;
  while(hit < n) {
    vector<int> now;
    int left = k;
    while(!pq.empty() && left) {
      now.push_back(pq.top().second);
      pq.pop();
      left--;
      hit++;
    }
    for(int x : now) {
      if(!--deg[a[x]]) pq.push({w[a[x]], a[x]});
    }
    days++;
  }
  cout << days << '\n';
}