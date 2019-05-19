// Benelux Algorithm Programming Contest preliminaries 2018
// C - Criss-Cross Cables
// https://open.kattis.com/problems/crisscrosscables

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 5e5+5;

int x[ms];
int cur[ms];
int wire[ms];
priority_queue<ii, vector<ii>, greater<ii>> pq;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> wire[i];
  }
  sort(wire, wire+m);
  for(int i = 0; i < n-1; i++) {
    cur[i] = i+1;
    pq.push({x[i+1] - x[i], i});
  }
  for(int i = 0; i < m; i++) {
    if(pq.empty() || pq.top().first > wire[i]) {
      cout << "no\n";
      return 0;
    }
    int k = pq.top().second;
    cur[k]++;
    pq.pop();
    if(cur[k] < n) pq.push({x[cur[k]] - x[k], k});
  }
  cout << "yes\n";
}