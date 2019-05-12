// North America Qualifier 2018
// M - Triangular Clouds
// https://open.kattis.com/problems/triangularclouds

#include <bits/stdc++.h>
using namespace std;

struct PT {
	int x, y;
	PT(int x = 0, int y = 0) : x(x), y(y) {}
	PT operator + (const PT &p) { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) { return PT(x - p.x, y - p.y); }
	PT operator * (int c) { return PT(x * c, y * c); }
	PT operator / (int c) { return PT(x / c, y / c); }
	bool operator <(const PT &p) const {
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator > (const PT &p) const {
		if(x != p.x) return x > p.x;
		return y > p.y;
	}
	bool operator ==(const PT &p) const {
		return x == p.x && y == p.y;
	}
};

typedef pair<PT, PT> pp;

const int inf = 0x3f3f3f3f;

map<pp, set<pp>> seg[2];

pp findLine(PT a, PT b) {
  b = b - a;
  if(b < PT()) b = PT() - b;
  if(b.x == 0) b.y = 1;
  else if(b.y == 0) b.x = 1;
  else {
    b = b / __gcd(abs(b.x), abs(b.y));
  }
  if(b.x == 0) a.y = 0;
  else if(b.y == 0) a.x = 0;
  else a = a - b * (a.x/b.x);
  if(a < PT()) a = a + b;
  return pp(a, b);
}

void insert(map<pp, set<pp>> &s, PT a, PT b) {
  pp line = findLine(a, b);
  if(a > b) swap(a, b);
  auto it = s[line].lower_bound(pp(a, PT(-inf, -inf)));
  if(it != s[line].begin()) {
    it--;
    if(it->second > a) {
      auto cur = *it;
      s[line].erase(it);
      s[line].insert(pp(cur.first, a));
      s[line].insert(pp(a, cur.second));
    }
  }
  it = s[line].lower_bound(pp(b, PT(-inf, -inf)));
  if(it != s[line].begin()) {
    it--;
    if(it->second > b) {
      auto cur = *it;
      s[line].erase(it);
      s[line].insert(pp(cur.first, b));
      s[line].insert(pp(b, cur.second));
    }
  }
  vector<pp> erased;
  for(it = s[line].lower_bound(pp(a, PT(-inf, -inf))); it != s[line].end() && it->first < b; it++) {
    erased.push_back(*it);
  }
  s[line].erase(s[line].lower_bound(pp(a, PT(-inf, -inf))), s[line].lower_bound(pp(b, PT(-inf, -inf))));
  for(auto p : erased) {
    PT l = p.first;
    PT r = p.second;
    if(a < l) {
      s[line].insert(pp(a, l));
    }
    a = r;
  }
  if(a < b) {
    s[line].insert(pp(a, b));
  }
  if(s[line].empty()) {
    s.erase(line);
  }
}

bool equal() {
  if(seg[0].size() != seg[1].size()) return 0;
  auto a = seg[0].begin();
  auto b = seg[1].begin();
  while(a != seg[0].end()) {
    if(a->first != b->first || a->second.size() != b->second.size()) return 0;
    auto x = a->second.begin();
    auto y = b->second.begin();
    while(x != a->second.end()) {
      if(*x != *y) return 0;
      x++;
      y++;
    }
    a++;
    b++;
  }
  return 1;
}

set<pp> temp;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  for(int t = 0; t < 2; t++) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      PT a, b, c;
      cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
      insert(seg[t], a, b);
      insert(seg[t], b, c);
      insert(seg[t], c, a);
    }
    for(auto &p : seg[t]) {
      auto &s = p.second;
      auto it = s.begin();
      auto cur = *it;
      it++;
      while(it != s.end()) {
        if(it->first == cur.second) {
          cur.second = it->second;
        } else {
          temp.insert(cur);
          cur = *it;
        }
        it++;
      }
      p.second = temp;
      temp.clear();
    }
  }
  if(equal()) {
    cout << "yes\n";
  } else {
    cout << "no\n";
  }
}