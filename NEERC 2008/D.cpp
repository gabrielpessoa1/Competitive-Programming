#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int ms = 2005;

int x1[ms], y1[ms], x2[ms], y2[ms], t[ms];

map<int, int> dicX, dicY;
int iDicY[ms];
int iDicX[ms];
int dist[ms][ms][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans[ms][ms];

main() {
  #ifdef ONLINE_JUDGE
  freopen("drive.in", "r", stdin);
  freopen("drive.out", "w", stdout);
  #endif  
  int xa, ya, xb, yb, n;
  cin >> xa >> ya >> xb >> yb;
  dicX[xa] = dicX[xb] = 0;
  dicY[ya] = dicY[yb] = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> t[i];
    dicX[x1[i]] = 0;
    dicX[x2[i]] = 0;
    dicY[y1[i]] = 0;
    dicY[y2[i]] = 0;
  }
  int xz = 0, yz = 0;
  for(auto &p : dicX) {
    iDicX[xz] = p.first;
    p.second = xz++;
  }
  for(auto &p : dicY) {
    iDicY[yz] = p.first;
    p.second = yz++;
  }
  memset(dist, 63, sizeof dist);
  for(int i = 0; i < xz; i++) {
    for(int j = 0; j < yz; j++) {
      if(i > 0) dist[i][j][2] = dist[i-1][j][0] = (iDicX[i] - iDicX[i-1]) * 10;
      if(j > 0) dist[i][j][3] = dist[i][j-1][1] = (iDicY[j] - iDicY[j-1]) * 10;
    }
  }
  for(int k = 0; k < n; k++) {
    x1[k] = dicX[x1[k]]; 
    x2[k] = dicX[x2[k]]; 
    y1[k] = dicY[y1[k]]; 
    y2[k] = dicY[y2[k]];
    for(int i = x1[k]+1; i <= x2[k]; i++) {
      for(int j = y1[k]+1; j <= y2[k]; j++) {
        if(i < x2[k]) dist[i][j][3] = dist[i][j-1][1] = dist[i][j][3] / 10 * t[k];
        if(j < y2[k]) dist[i][j][2] = dist[i-1][j][0] = dist[i][j][2] / 10 * t[k];
      }
    }
  }
  xa = dicX[xa]; xb = dicX[xb]; ya = dicY[ya]; yb = dicY[yb];
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  memset(ans, 63, sizeof ans);
  ans[xa][ya] = 0;
  pq.push({0, {xa, ya}});
  while(!pq.empty()) {
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    int curD = pq.top().first;
    pq.pop();
    if(curD != ans[x][y]) continue;
    for(int d = 0; d < 4; d++) {
      int x2 = x + dx[d], y2 = y + dy[d];
      if(x2 >= 0 && x2 < xz && y2 >= 0 && y2 < yz && curD + dist[x][y][d] < ans[x2][y2]) {
        ans[x2][y2] = curD + dist[x][y][d];
        pq.push(iii(ans[x2][y2], ii(x2, y2)));
      }
    }
  }
  cout << ans[xb][yb] << '\n';
}