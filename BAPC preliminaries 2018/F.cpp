// Benelux Algorithm Programming Contest preliminaries 2018
// F - Floating Points
// https://open.kattis.com/problems/floatingpoints

#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;
const double inf = 1e100;
const double eps = 1e-7;

struct PT {
  int x, y;
	PT(int x = 0, int y = 0) : x(x), y(y) {}
	PT operator - (const PT &p) { return PT(x - p.x, y - p.y); }
};

int cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

int n, b;
PT v[ms];
int leon[ms];
int vis[ms];

int queryEdge(PT p) {
  int cur = -1;
  double curY = inf;
  for(int i = 0; i < n; i++) {
    int j = (i+1)%n;
    PT a = v[i], b = v[j];
    if(b.x < a.x) swap(a, b);
    if(p.x > a.x && p.x < b.x) {
      double k = (1.0 * p.x - a.x) / (b.x - a.x);
      double h = (b.y - a.y)*k + a.y;
      if(h >= p.y && h < curY) {
        curY = h;
        cur = i;
      }
    }
  }
  return cur;
}

int dfs(int i) {
  if(vis[i]) return leon[i];
  vis[i] = 1;
  PT a = v[i];
  PT b = v[(i+1)%n];
  int toCheck = 0;
  if(b.y > a.y) {
    swap(a, b);
    toCheck = 1;
  }
  if(a.y == b.y) leon[i] = a.y;
  else {
    int l = (i+1)%n;
    int r = (i+2)%n;
    int start = l;
    if(!toCheck) {
      l = i;
      r = (i-1+n)%n;
      start = r;
    }
    if((a.x > b.x) == (v[r].x > v[l].x)) {
      if(v[r].y <= v[l].y) leon[i] = a.y;
      else leon[i] = dfs(start);
    } else if(v[r].y <= v[l].y && ((cross(a-b, v[r] - v[l]) > 0) == (a.x < b.x))) {
      leon[i] = a.y;
    } else {
      int k = queryEdge(a);
      if(k == -1) leon[i] = 0x3f3f3f3f;
      else leon[i] = dfs(k);
    }
  }
  return leon[i];
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> b;
  for(int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }
  for(int i = 0; i < n; i++) {
    dfs(i);
  }
  int ans = 0;
  for(int i = 0; i < b; i++) {
    int x;
    cin >> x;
    PT p;
    p.y = -1e5-1;
    p.x = x;
    int k = queryEdge(p);
    if(k > -1 && leon[k] <= 0) ans++;
  }
  cout << ans << endl;
}