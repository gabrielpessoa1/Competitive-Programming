#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;

const double inf = 1e100, eps = 1e-9;

struct PT {
  double x, y;
  PT(double x = 0, double y = 0) : x(x), y(y) {}
  PT operator + (const PT &p) { return PT(x + p.x, y + p.y); }
  PT operator - (const PT &p) { return PT(x - p.x, y - p.y); }
  PT operator * (double c) { return PT(x * c, y * c); }
  PT operator / (double c) { return PT(x / c, y / c); }
  bool operator <(const PT &p) const {    
    if(fabs(x-p.x) >= eps) return x < p.x;
    return fabs(y-p.y) >= eps && y < p.y;
  }
};

double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

double dist(PT p, PT q) { return hypot(p.x-q.x, p.y-q.y); }

vector<PT> convexHull(vector<PT> p) {
  int n = p.size(), k = 0;
  vector<PT> h(2*n);
  sort(p.begin(), p.end());
  for(int i = 0; i < n; i++) {
    while(k >= 2 && cross(h[k-1] - h[k-2], p[i] - h[k-2]) <= 0) k--;
    h[k++] = p[i];
  }
  for(int i = n-2, t = k+1; i >= 0; i--) {
    while(k>=t && cross(h[k-1] - h[k-2], p[i] - h[k-2]) <= 0) k--;
    h[k++] = p[i];
  }
  h.resize(k-1); 
  return h;
}

main() {
  cout << fixed << setprecision(8);
  int c;
  cin >> c;
  vector<PT> pts(c);
  for(int i = 0; i < c; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  vector<PT> ch = convexHull(pts);
  int n = ch.size();
  int j = 1;
  double ans = 0;
  for(int i = 0; i < n; i++) {
    while(dist(ch[i], ch[(j+1)%n]) > dist(ch[i], ch[j])) {
      j = (j+1)%n;
    }
    ans = max(ans, dist(ch[i], ch[j]));
  }
  cout << ans << '\n';
}