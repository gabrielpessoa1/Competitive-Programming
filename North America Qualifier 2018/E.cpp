// North America Qualifier 2018
// E - Fruit Slicer
// https://open.kattis.com/problems/fruitslicer

#include <bits/stdc++.h>
using namespace std;

const int ms = 105;

double eps = 1e-7;

struct PT {
	double x, y;
	PT(double x = 0, double y = 0) : x(x), y(y) {}
	PT operator + (const PT &p) { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) { return PT(x - p.x, y - p.y); }
	PT operator * (double c) { return PT(x * c, y * c); }
	PT operator / (double c) { return PT(x / c, y / c); }
	bool operator <(const PT &p) const {
		if(fabs(x - p.x) >= eps) return x < p.x;
		return fabs(y - p.y) >= eps && y < p.y;
	}
};

double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
PT normalize(PT p) { return p / sqrt(dot(p, p)); }
double dist(PT p, PT q) {return hypot(p.x-q.x, p.y-q.y); }

PT rotateCCW(PT p, double t) {
    return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

vector<pair<PT, PT>> getTangentSegs(PT a, PT b) {
  vector<pair<PT, PT>> ans;
  double d = dist(a, b);
  if(d < eps) {
    return ans;
  }
  double u = acos(0);
  PT dc = normalize(b-a);
  ans.push_back(make_pair(a + rotateCCW(dc, u), b + rotateCCW(dc, u)));
  ans.push_back(make_pair(a + rotateCCW(dc, -u), b + rotateCCW(dc, -u)));
  if(2 - eps >= d) return ans;
  double v = acos(2/d);
  PT dc2 = normalize(a-b);
  ans.push_back(make_pair(a+rotateCCW(dc, v), b + rotateCCW(dc2, v)));
  ans.push_back(make_pair(a+rotateCCW(dc, -v), b + rotateCCW(dc2, -v)));
  return ans;
}

PT projectPointLine(PT a, PT b, PT c) {
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}

bool circleLineIntersection(PT a, PT b, PT c) {
  return dist(c, projectPointLine(a, b, c)) <= 1;
}

PT p[ms];


int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      auto v = getTangentSegs(p[i], p[j]);
      for(auto x : v) {
        int cur = 0;
        for(int k = 0; k < n; k++) {
          if(circleLineIntersection(x.first, x.second, p[k])) cur++;
        }
        ans = max(cur, ans);
      }
    }
  }
  if(!ans) ans = n;
  cout << ans << '\n';
}