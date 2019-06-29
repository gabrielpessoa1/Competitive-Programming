#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1e5+5;
 
int pre[ms];
int arr[ms];
map<int, int> dic;
vector<int> xorPos[ms];
int lastZero[ms][32];
vector<pair<int, int>> changePos;
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  #ifdef ONLINE_JUDGE
  freopen("hack.in", "r", stdin);
  freopen("hack.out", "w", stdout);
  #endif
  int n;
  cin >> n;
  dic[0] = 0;
  int z = 1;
  xorPos[0].push_back(0);
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    pre[i] = pre[i-1] ^ arr[i];
    if(!dic.count(pre[i])) dic[pre[i]] = z++;
    int idx = dic[pre[i]];
    xorPos[idx].push_back(i);
    for(int j = 0; j < 31; j++) {
      if(arr[i] & (1 << j)) lastZero[i][j] = lastZero[i-1][j];
      else lastZero[i][j] = i;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    changePos = {{0, -1}};
    for(int j = 0; j < 31; j++) {
      changePos.emplace_back(lastZero[i][j], j);
    }
    sort(changePos.begin(), changePos.end());
    int curXor = ((1 << 31) - 1) ^ pre[i];
    int curPos = i;
    for(int j = changePos.size() - 1; j >= 0; j--) {
      if(curPos != changePos[j].first) {
        //qntidade de curxor entre curPos-1 e i-1
        int tempAns = ans;
        if(dic.count(curXor)) {
          int p = dic[curXor];
          ans += (upper_bound(xorPos[p].begin(), xorPos[p].end(), curPos-1) - 
                  lower_bound(xorPos[p].begin(), xorPos[p].end(), changePos[j].first));
        }
        //cout << curPos << ' ' << i << ' ' << curXor << ' ' << ans - tempAns << endl;
        curPos = changePos[j].first;
      }
      if(j > 0) curXor ^= (1 << changePos[j].second);
    }
  }
  cout << ans << '\n';
}