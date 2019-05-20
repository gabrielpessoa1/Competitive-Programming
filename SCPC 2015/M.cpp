#include <bits/stdc++.h>
using namespace std;

const int ms = 10005;

map<string, int> dic;
string iDic[ms];
int z;
int s[ms][400];
int e[ms][400];
vector<string> ans;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    z = 0;
    dic.clear();
    ans.clear();
    memset(s, 0, sizeof s);
    memset(e, 0, sizeof e);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      string str;
      int a, b, v;
      cin >> str >> a >> b >> v;
      for(int j = 0; j < v; j++) {
        cin >> str;
        if(!dic.count(str)) {
          iDic[z] = str;
          dic[str] = z++;
        }
        int idx = dic[str];
        s[idx][a]++;
        e[idx][b]++;
      }
    }
    for(int i = 0; i < z; i++) {
      int cur = 0;
      for(int j = 1; j <= 365; j++) {
        cur += s[i][j];
        if(cur > 1) {
          ans.push_back(iDic[i]);
          break;
        }
        cur -= e[i][j];
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto &s : ans) cout << s << '\n';
  }
}