#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;
const int mod = 1e9+7;

struct PT {
  int x, y;
  PT(int x = 0, int y = 0) : x(x), y(y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  bool operator <(const PT &p) const {
    if(x != p.x) return x < p.x;
    return y < p.y;
  }
};

int dot(PT p, PT q) {
  return p.x * q.x + p.y * q.y;
}
int cross(PT p, PT q) {
  return p.x * q.y - p.y * q.x;
}

vector<PT> convexHull(vector<PT> p) {
  int n = p.size(), k = 0;
  vector<PT> h(2*n);
  sort(p.begin(), p.end());
  for(int i = 0; i < n; i++) {
    while(k >= 2 && cross(h[k-1] - h[k-2], p[i] - h[k-2]) < 0) k--;
    h[k++] = p[i];
  }
  for(int i = n - 2, t = k + 1; i >= 0; i--) {
    while(k >= t && cross(h[k-1] - h[k-2], p[i] - h[k-2]) < 0) k--;
    h[k++] = p[i];
  }
  h.resize(k);
  return h;
}

bool ptInSegment(PT a, PT b, PT c) {
  bool x = min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x);
  bool y = min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
  return x && y && cross(b-a, c-a) == 0;
}

bool ptInsideTriangle(PT p, PT a, PT b, PT c) {
  if(cross(b-a, c-b) < 0) swap(a, b);
  int x = cross(b-a, p-b);
  int y = cross(c-b, p-c);
  int z = cross(a-c, p-a);
  if(x > 0 && y > 0 && z > 0) return true;
  if(!x) return ptInSegment(a, b, p);
  if(!y) return ptInSegment(b, c, p);
  if(!z) return ptInSegment(c, a, p);
  return false;
}

bool pointInConvexPolygon(const vector<PT> &p, PT q) {
  for(int i = 1; i < (int) p.size() - 2; i++) {
    if(ptInsideTriangle(q, p[i], p[i+1], p[0])) return true;
  }
  return false;
}

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    int c, p;
    vector<PT> v;
    cin >> c >> p;
    for(int i = 0; i < c; i++) {
      int x, y;
      cin >> x >> y;
      v.emplace_back(x, y);
    }
    v = convexHull(v);
    cout << "Case " << T << '\n';
    for(int i = 0; i < (int) v.size(); i++) {
      cout << v[i].x << ' ' << v[i].y << '\n';
    }
    for(int i = 0; i < p; i++) {
      PT pt;
      cin >> pt.x >> pt.y;
      cout << pt.x << ' ' << pt.y << " is ";
      if(pointInConvexPolygon(v, pt)) cout << "un";
      cout << "safe!\n";
    }
    if(T != t) cout << '\n';
  }
}