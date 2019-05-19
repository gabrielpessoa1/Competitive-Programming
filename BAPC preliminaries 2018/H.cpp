// Benelux Algorithm Programming Contest preliminaries 2018
// H - H to O
// https://open.kattis.com/problems/htoo

#include <bits/stdc++.h>

using namespace std;

const int ms = 300;
const int inf = 0x3f3f3f3f;

int in[ms], out[ms];

void convert(string s, int in[]) {
  int idx = 0;
  while(idx < s.size()) {
    int qnt = 0;
    char c = s[idx++];
    while(s[idx] >= '0' && s[idx] <= '9') {
      qnt = qnt * 10 + s[idx] - '0';
      idx++;
    }
    in[c] += max(1, qnt);
  }
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
  string s, t;
  int k;
  cin >> s >> k >> t;
  convert(s, in); convert(t, out);
  int ans = inf;
  for(int i = 'A'; i <= 'Z'; i++) {
    if(out[i] > 0) ans = min(ans, in[i]*k/out[i]);
  }
  cout << ans << endl;
}
