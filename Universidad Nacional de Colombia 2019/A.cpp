#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

#define int long long

struct PT {
  int x, y;
  PT (int x = 0, int y = 0) : x(x), y(y) {};
  PT operator + (const PT &p) const {return PT(x+p.x, y+p.y); };
  PT operator - (const PT &p) const {return PT(x-p.x, y-p.y); };
  bool operator < (const PT &p) const {
    if (p.x != x) return x < p.x;
    return y < p.y;
  }
  bool operator != (const PT &p) const {
    return (p.x != x) || (p.y != y);
  }
  bool operator == (const PT &p) const {
    return (p.x == x) && (p.y == y);
  }
};

int cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }

PT rotateCCW90(PT p) { return PT(-p.y, p.x); }

PT getVec (PT d) {
  if (d.x == 0) return {0, 1};
  if (d.y == 0) return {1, 0};
  int g = __gcd(abs(d.x), abs(d.y));
  if(d.x < 0) g = -g;
  return PT{d.x/g, d.y/g};
}

bool parallel (PT a, PT b, PT c, PT d) {
  return cross(b - a, c - d) == 0;
}

bool collinear (PT a, PT b, PT c, PT d) {
  return parallel(a, b, c, d) && cross(a - b, a - c) == 0 && cross(c - d, c - a) == 0;
}

pair<double, double> getB (PT a, PT dir) {
  if (dir.x == 0) {
    return {a.x, 0};
  } else if (dir.y == 0) {
    return {0, a.y};
  }
  double t = 1.0*(0-a.y)/dir.y;
  return {a.x+dir.x*t, a.y+dir.y*t};
}

map<PT, int> mp;
main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<PT, int>> v;
    for (int i = 0; i < n; i++) {
      PT a, b;
      cin >> a.x >> a.y >> b.x >> b.y;
      if (a == b) continue;
      if(b < a) swap(a, b);
      v.push_back(make_pair(getVec(b-a), cross(getVec(b-a), a)));
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < 3; j++) {
        v[i].x = rotateCCW90(v[i].x);
        ans += mp[v[i].x];
      }
      v[i].x = rotateCCW90(v[i].x);
      mp[v[i].x]++;
    }
    cout << ans << endl;
    mp.clear();
  }
}
