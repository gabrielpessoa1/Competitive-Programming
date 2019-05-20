#include <bits/stdc++.h>
using namespace std;

const int ms = 10005;

map<string, int> dic;
string iDic[ms];
int z;
int s[ms][400];
int e[ms][400];
vector<string> ans;

bool solve(vector<int> &v, vector<int> &m) {
  for(int i = 1; i <= 5; i++) {
    if(v[i] + m[i] == 0) {
      for(int j = 1; j < i; j++) {
        v[j]--;
        v[i-j]--;
        m[i]++;
        if(v[j] >= 0 && v[i-j] >= 0 && solve(v, m)) return 1;
        v[j]++; v[i-j]++; m[i]--;
      }
      return 0;
    }
  }
  return 1;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    vector<int> v(6);
    vector<int> m(6);
    for(char c : s) {
      v[c+1-'A']++;
    }
    if(solve(v, m)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}