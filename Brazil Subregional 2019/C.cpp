#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;
typedef pair<int, i4> event;

const int ms = 2e5+5;
const int SH = 1e5+2;

set<ii> lft[ms], rigt[ms], up[ms], down[ms];
set<ii> lftD1[ms], lftD2[ms];
set<ii> rigtD1[ms], rigtD2[ms];
set<ii> upD1[ms], upD2[ms];
set<ii> downD1[ms], downD2[ms];
int x[ms], y[ms];
int dead[ms];
char d[ms];
priority_queue<event, vector<event>, greater<event>> pq;

void newEvent(int t, int a, int b, int x, int y) {
  pq.push({t, {{a, b}, {x, y}}});
}

ii bef(set<ii> &s, int p) {
  auto it = s.upper_bound({p, ms});
  if(it == s.begin()) return {-1, -1};
  else {
    it--;
    return *it;
  }
}

ii aft(set<ii> &s, int p) {
  auto it = s.lower_bound({p, 0});
  if(it == s.end()) return {-1, -1};
  else {
    return *it;
  }
}

void kill(int i) {
  dead[i] = 1;
  if(d[i] == 'N') {
    down[x[i]].erase({y[i], i});
    downD1[x[i]-y[i]+SH].erase({x[i], i});
    downD2[x[i]+y[i]].erase({x[i], i});
  }
  if(d[i] == 'S') {
    up[x[i]].erase({y[i], i});
    upD1[x[i]-y[i]+SH].erase({x[i], i});
    upD2[x[i]+y[i]].erase({x[i], i});
  }
  if(d[i] == 'L') {
    rigt[y[i]].erase({x[i], i});
    rigtD1[x[i]-y[i]+SH].erase({y[i], i});
    rigtD2[x[i]+y[i]].erase({y[i], i});
  }
  if(d[i] == 'O') {
    lft[y[i]].erase({x[i], i});
    lftD1[x[i]-y[i]+SH].erase({y[i], i});
    lftD2[x[i]+y[i]].erase({y[i], i});
  }
}

void getAgain(int i) {
  if(d[i] == 'N') {
    ii p = bef(up[x[i]], y[i]-1);
    if(~p.first) { newEvent(y[i] - p.first, i, p.second, x[i], (p.first+y[i])/2); };
    p = bef(rigtD1[x[i]-y[i]+SH], y[i]-1);
    if(~p.first) { newEvent((y[i] - p.first)*2, i, p.second, x[i], p.first); }
    p = bef(lftD2[x[i]+y[i]], y[i]-1);
    if(~p.first) { newEvent((-p.first + y[i])*2, i, p.second, x[i], p.first); }
  }
  if(d[i] == 'S') {
    ii p = aft(down[x[i]], y[i]+1);
    if(~p.first) { newEvent(-y[i] + p.first, i, p.second, x[i], (p.first+y[i])/2); };
    p = aft(lftD1[x[i]-y[i]+SH], y[i]+1);
    if(~p.first) { newEvent((-y[i] + p.first)*2, i, p.second, x[i], p.first); }
    p = aft(rigtD2[x[i]+y[i]], y[i]+1);
    if(~p.first) { newEvent((p.first - y[i])*2, i, p.second, x[i], p.first); }
  }
  if(d[i] == 'L') {
    ii p = aft(lft[y[i]], x[i]+1);
    if(~p.first) { newEvent(-x[i] + p.first, i, p.second, (p.first+x[i]+1)/2, y[i]); };
    p = aft(downD1[x[i]-y[i]+SH], x[i]+1);
    if(~p.first) { newEvent((-x[i] + p.first)*2, i, p.second, p.first, y[i]); }
    p = aft(upD2[x[i]+y[i]], x[i]+1);
    if(~p.first) { newEvent((p.first - x[i])*2, i, p.second, p.first, y[i]); }
  }
  if(d[i] == 'O') {
    ii p = bef(rigt[y[i]], x[i]-1);
    if(~p.first) { newEvent(x[i] - p.first, i, p.second, (p.first+x[i]+1)/2, y[i]); };
    p = bef(upD1[x[i]-y[i]+SH], x[i]-1);
    if(~p.first) { newEvent((x[i] - p.first)*2, i, p.second, p.first, y[i]); }
    p = bef(downD2[x[i]+y[i]], x[i]-1);
    if(~p.first) { newEvent((-p.first + x[i])*2, i, p.second, p.first, y[i]); }
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m, c; 
  cin >> n >> m >> c;
  for(int i = 0; i < c; i++) {
    string s;
    cin >> y[i] >> x[i] >> s;
    d[i] = s[0];
    if(d[i] == 'N') {
      down[x[i]].insert({y[i], i});
      downD1[x[i]-y[i]+SH].insert({x[i], i});
      downD2[x[i]+y[i]].insert({x[i], i});
    }
    if(d[i] == 'S') {
      up[x[i]].insert({y[i], i});
      upD1[x[i]-y[i]+SH].insert({x[i], i}); 
      upD2[x[i]+y[i]].insert({x[i], i});
    }
    if(d[i] == 'L') {
      rigt[y[i]].insert({x[i], i});
      rigtD1[x[i]-y[i]+SH].insert({y[i], i});
      rigtD2[x[i]+y[i]].insert({y[i], i});
    }
    if(d[i] == 'O') {
      lft[y[i]].insert({x[i], i});
      lftD1[x[i]-y[i]+SH].insert({y[i], i});
      lftD2[x[i]+y[i]].insert({y[i], i});
    }
  }
  for(int i = 0; i < c; i++) {
    getAgain(i);
  }
  int ans = c;
  while(!pq.empty()) {
    int t = pq.top().first;
    int c1 = pq.top().second.first.first, c2 = pq.top().second.first.second;
    int x = pq.top().second.second.first, y = pq.top().second.second.second;
    pq.pop();
    if(~c1 && dead[c1]) {
      if(~c2 && !dead[c2]) getAgain(c2);
      continue;
    }
    if(~c2 && dead[c2]) {
      if(~c1 && !dead[c1]) getAgain(c1);
      continue;
    }
    if(~c1) {
      kill(c1);
      ans--;
    }
    if(~c2) {
      kill(c2);
      ans--;
    }
    ii p = bef(up[x], y-(t+1)/2);
    if(~p.first) { newEvent((y - p.first)*2, p.second, -1, x, y); }
    p = aft(down[x], y+(t+1)/2);
    if(~p.first) { newEvent((-y + p.first)*2, p.second, -1, x, y); }
    p = bef(rigt[y], x-(t+1)/2);
    if(~p.first) { newEvent((x - p.first)*2, p.second, -1, x, y); }
    p = aft(lft[y], x+(t+1)/2);
    if(~p.first) { newEvent((-x + p.first)*2, p.second, -1, x, y); }
  }
  cout << ans << endl;
}