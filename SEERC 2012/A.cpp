#include <bits/stdc++.h>
using namespace std;

const int ms = 10000;

int g[ms][1005];
int sz[ms];
int a[ms];
int blck[ms];
queue<int> q[ms];
vector<int> temp;

main() {
  #ifdef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
  #endif
  cin.tie(0); ios::sync_with_stdio(0);
  string s;
  while(getline(cin, s)) {
    stringstream ss(s);
    int n = 0;
    for(int i = 0; ss >> a[i]; i++) {
      n++;
      q[a[i]].push(i);
    }
    for(int i = 0; i < n; i++) {
      sz[i] = 0;
    }
    bool valid = true;
    for(int i = 1000; i > 0; i--) {
      while(!q[i].empty()) {
        int x = q[i].front();
        q[i].pop();
        if(valid) {
          blck[i] = -1;
          for(int j = i; j > 0 && a[x]; j--) {
            blck[j-1] = -1;
            while(!q[j].empty() && a[x] && q[j].front() != blck[j]) {
              int y = q[j].front();
              q[j].pop();
              if(blck[j-1] == -1) {
                blck[j-1] = y;
              }
              a[x]--;
              g[x][sz[x]++] = y;
              g[y][sz[y]++] = x;
              a[y]--;
              q[j-1].push(y);
            }
          }
          if(a[x]) valid = false;
        }
      }
    }
    if(!valid) {
      cout << "fail\n";
    } else {
      for(int i = 0; i < n; i++) {
        int pt = 0;
        sort(g[i], g[i]+sz[i]);
        for(int j = 0; j < n; j++) {
          if(pt < sz[i] && g[i][pt] == j) {
            cout << 1 << ' ';
            pt++;
          } else {
            cout << 0 << ' ';
          }
        }
        cout << '\n';
      }
    }
    cout << '\n';
  }
}