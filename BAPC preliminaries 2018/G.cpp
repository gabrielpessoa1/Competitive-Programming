// Benelux Algorithm Programming Contest preliminaries 2018
// G - Green Light
// https://open.kattis.com/problems/greenlight

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int mod;
vector<ii> segs;
vector<ii> mySegs;
vector<ii> novosSegs;

int cnt(vector<ii> &v) {
  int ans = 0;
  for(auto p : v) ans += p.second - p.first + 1;
  return ans;
}

void insert(int x, int y) {
  x = ((x % mod) + mod) % mod;
  y = ((y % mod) + mod) % mod;
  novosSegs.clear();
  mySegs.clear();
  if(x <= y) {
    mySegs.push_back(ii(x, y));
  } else {
    mySegs.push_back(ii(0, y));
    mySegs.push_back(ii(x, mod-1));
  }
  for(auto p1 : mySegs) {
    for(auto p2 : segs) {
      int l = max(p1.first, p2.first);
      int r = min(p1.second, p2.second);
      if(l <= r) {
        novosSegs.push_back(ii(l, r));
      }
    }
  }
  if(novosSegs.empty()) {
    cout << 0 << endl;
    exit(0);
  }
  sort(novosSegs.begin(), novosSegs.end());
  ii cur = novosSegs[0];
  mySegs.clear();
  for(int i = 1; i < novosSegs.size(); i++) {
    if(cur.second >= novosSegs[i].first) {
      cur.second = novosSegs[i].second;
    } else {
      mySegs.push_back(cur);
      cur = novosSegs[i];
    }
  }
  mySegs.push_back(cur);
}


int main() {
	cin.tie(0); ios::sync_with_stdio(0);
  cout << fixed << setprecision(7);
  int tg, ty, tr;
  cin >> tg >> ty >> tr;
  mod = tg + ty + tr;
  int n;
  cin >> n;
  segs.push_back({0, mod-1});
  for(int i = 0; i < n; i++) {
    int x; string s;
    cin >> x >> s;
    if(s == "green") {
      insert(x-tg+1, x);
      mySegs.swap(segs);
    } else if(s == "yellow") {
      x -= tg;
      insert(x-ty+1, x);
      mySegs.swap(segs);
    } else {
      x -= tg + ty;
      insert(x-tr+1, x);
      mySegs.swap(segs);
    }
  }
  int x; string s;
  cin >> x >> s;
  int val;
  if(s == "green") {
    val = x-tg+1;
  } else if(s == "yellow") {
    x -= tg;
    val = x - ty + 1;
  } else {
    x -= tg + ty;
    val = x - tr + 1;
  }
  insert(val, x);
  int sz = cnt(segs);
  int newSz = cnt(mySegs);
  cout << 1.0 * newSz / sz << '\n';
}
