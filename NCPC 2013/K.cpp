#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ld, ii> pdii;

const ld hour = 60*60;
const ld pi = acos(-1);
const ld inf = 1e100;
const int range = 1000;
const int ms = 1005;

int arr[ms][ms];
ld k[ms][ms];
ld k2[ms][ms];
ld dist[ms][ms];
ld dist2[ms][ms];
int mark[ms][ms];
int mark2[ms][ms];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ld a, m;
int w, h, x, y;
priority_queue<pdii, vector<pdii>, greater<pdii>> pq;

void calc(int b1, int b2) {
  dist[x][y] = 0;
  mark[x][y] = 1;
  pq.push({0, {x, y}});
  while(!pq.empty()) {
    int a = pq.top().second.first;
    int b = pq.top().second.second;
    pq.pop();
    for(int dir = 0; dir < 4; dir++) {
      int c = a + dx[dir], d = b + dy[dir];
      if(c >= 0 && c < h && d >= 0 && d < w && abs(arr[a][b] - arr[c][d]) <= range && !mark[c][d] && max(dist[a][b], k[c][d]+b1)+m <= 12*hour-k[c][d]-b2) {
        mark[c][d] = 1;
        dist[c][d] = max(dist[a][b], k[c][d]+b1)+m;
        pq.push({dist[c][d], {c, d}});
      }
    }
  }
}

main() {
  cout << fixed << setprecision(9);
  cin >> a >> m;
  cin >> w >> h >> y >> x;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> arr[i][j];
      ld lo = 0, hi = 6*hour;
      for(int it = 0; it < 100; it++) {
        ld mi = (lo+hi)/2;
        if(0.5*a*(cos(mi/hour*2*pi/12)+1)*1000 > arr[i][j]) lo = mi;
        else hi = mi;
      }
      k[i][j] = arr[i][j] > a * 1000 ? -hour : acos(arr[i][j]/(500*a)-1)*6*hour/pi;
    }
  }
  calc(0, hour);
  swap(dist, dist2);
  swap(mark, mark2);
  calc(hour, 0);
  ld ans = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      //if(mark[i][j]) cout << i << ' ' << j << " = " << dist[i][j] << endl;
      if(mark[i][j] && mark2[i][j] && dist[i][j] + dist2[i][j] <= 12*hour) ans = max(ans, 10 * hypot((ld) (x-i), (ld) (y-j)));
    }
  }
  cout << ans << '\n';
}