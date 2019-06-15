// VTEX Code Cup 2019
// G - Punctual Chefs
// https://vtexcc19.kattis.com/problems/vtexcc19.punctualchefs

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 0x3f3f3f3f;
const int ms = 1e5+5;
const int mod = 1e9+7;

priority_queue<ii, vii, greater<ii>> pq;
int type[ms];
int ans[ms];
int d[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t >> d[i];
    pq.push({t, i});
  }
  int a = 0, b = 0;
  int fimA = 0, fimB = 0;
  while(!pq.empty()) {
    int t = pq.top().first;
    int x = pq.top().second;
    pq.pop();
    if(x == -1) a--;
    else if(x == -2) b--;
    else {
      if(a <= b) {
        type[x] = 1;
        a++;
        ans[x] = fimA = max(t, fimA) + d[x];
        pq.push({ans[x], -1});
      } else {
        type[x] = 2;
        b++;
        ans[x] = fimB = max(t, fimB) + d[x] * k;
        pq.push({ans[x], -2});
      }
    }
  }
  for(int i = 0; i < n; i++) {
    if(type[i] == 1) cout << "A ";
    else cout << "B ";
    cout << ans[i] << '\n';
  }
  return 0;
}