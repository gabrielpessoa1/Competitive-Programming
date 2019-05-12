// VTEX Code Cup 2019
// E - Fragile Diamonds
// https://vtexcc19.kattis.com/problems/vtexcc19.fragilediamonds

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int inf = 0x3f3f3f3f;

set<iii> s[30];
vector<int> ans;

bool sqrIntersect(int x1, int y1, int x2, int y2) {
    return 2*min(y1, y2) > abs(x1-x2);
}

bool intersect(int x, int y,  int idx) {
  auto it = s[idx].lower_bound({{x, 0}, 0});
  if(sqrIntersect(x, y, it->first.first, it->first.second)) {
    ans.push_back(it->second);
    s[idx].erase(it);
    return true;
  }
  it--;
  if(sqrIntersect(x, y, it->first.first, it->first.second)) {
    ans.push_back(it->second);
    s[idx].erase(it);
    return true;
  }
  return false;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int j = 0; j < 30; j++) {
    s[j].insert({{-inf, 0}, -1});
    s[j].insert({{inf, 0}, 1});
  }
  for(int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    for(int j = 0; j < 30; j++) {
      while(intersect(x, y, j));
    }
    sort(ans.begin(), ans.end());
    cout << ans.size();
    for(int i : ans) {
      cout << ' ' << i;
    }
    cout << '\n';
    ans.clear();
    for(int j = 0; j < 30; j++) {
      if((1 << (j+1)) > y) {
        s[j].insert({{x, y}, i});
        break;
      }
    }
  }
}