// World Finals 2019
// J - Miniature Golf
// https://open.kattis.com/problems/minigolf

#include <bits/stdc++.h>
using namespace std;

#define int long long

int sc[505][55];
pair<int, int> events[105];
pair<int, int> collisions[505*105];
int csz;

main() {
  int p, h;
  scanf("%lld%lld", &p, &h);
  for(int i = 0; i < p; i++) {
    for(int j = 0; j < h; j++) {
      scanf("%lld", &sc[i][j]);
    }
  }
  for(int i = 0; i < p; i++) {
    csz = 0;
    for(int j = 0; j < p; j++) {
      if(i == j) continue;
      for(int k = 0; k < h; k++) {
        events[k] = {sc[i][k], 0};
        events[k+h] = {sc[j][k], 1};
      }
      sort(events, events+h+h);
      int cur[2] = {h, h};
      int lastCur[2] = {0, 0};
      int curP[2] = {0, 0};
      int curEnd = 0;
      for(int k = 0; k <= h+h; k++) {
        if(k == h + h || events[k].first != curEnd) {
          if(cur[0] != cur[1]) {
            int x = (curP[1] - curP[0])/(cur[0] - cur[1]) + curEnd;
            if(!(curP[1] != curP[0] && (curP[1] > curP[0]) != (cur[0] > cur[1])) && x >= curEnd && (k == h + h || x < events[k].first)) {
              int pos[2];
              for(int idx = 0; idx < 2; idx++) {
                pos[idx] = curP[idx] + (x-curEnd)*cur[idx];
              }
              if(curP[0] == curP[1] && lastCur[0] > lastCur[1]) {
                collisions[csz++] = {x, -1};
                if(cur[0] < cur[1]) {
                  collisions[csz++] = {x+1, 1};
                }
              } else if(pos[0] == pos[1] && cur[0] > cur[1]) {
                if(curP[0] != curP[1]) collisions[csz++] = {x, -1};
              } else if(cur[0] < cur[1]) {
                if(curP[0] != curP[1] || lastCur[0] <= lastCur[1]) collisions[csz++] = {x+1, 1};
              } else {
                if(curP[0] != curP[1] || lastCur[0] > lastCur[1]) collisions[csz++] = {x+1, -1};
              }
            }
          } else if(curP[0] == curP[1] && lastCur[0] > lastCur[1]) {
            collisions[csz++] = {curEnd, -1};
          }
          if(k != h + h) {
            for(int idx = 0; idx < 2; idx++) {
              curP[idx] += cur[idx] * (events[k].first - curEnd);
              lastCur[idx] = cur[idx];
            }
            curEnd = events[k].first;
          }
        }
        cur[events[k].second]--;
      }
    }
    int rank = p;
    int ans = p;
    sort(collisions, collisions+csz);
    for(int j = 0; j < csz; j++) {
      rank -= collisions[j].second;
      ans = min(ans, rank);
    }
    printf("%lld\n", ans);
  }
}
