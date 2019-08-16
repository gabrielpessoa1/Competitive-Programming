#include <bits/stdc++.h>
using namespace std;

const int ms = 50;

int g[ms][ms];
int vis[ms];
vector<string> t;
queue<char> cons, vowel;
char dic[ms];

int solve(int a, int b, int c, int d, int e) {
  memset(vis, 0, sizeof vis);
  vis[a] = vis[b] = vis[c] = vis[d] = vis[e] = 1;
  for(int i = 0; i < 26; i++) {
    for(int j = i; j < 26; j++) {
      if(g[i][j] && vis[i] == vis[j]) return 0;
    }
  }
  for(int i = 0; i < 26; i++) {
    if(vis[i]) {
      dic[i] = vowel.front();
      vowel.pop();
    } else {
      dic[i] = cons.front();
      cons.pop();
    }
  }
  //cout << (char) ('A'+a) << ' ' << (char)('A'+b) << ' ' << (char)('A'+c) << ' ' << (char)('A'+d) << ' ' << (char)('A'+e) << endl;
  for(int i = 0; i < (int) t.size(); i++) {
    for(char c : t[i]) {
      if(c == ' ') cout << c;
      else cout << dic[c-'A'];
    }
    cout << '\n';
  }
  return 1;
}

main() {
  #ifdef ONLINE_JUDGE
  freopen("javanese.in", "r", stdin);
  freopen("javanese.out", "w", stdout);
  #endif  
  for(char c = 'A'; c <= 'Z'; c++) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      vowel.push(c);
    } else {
      cons.push(c);
    }
  }
  string w;
  while(getline(cin, w)) {
    t.push_back(w);
    stringstream ss(w);
    string s;
    while(ss >> s) {
      for(int i = 1; i < (int) s.size(); i++) {
        g[s[i-1]-'A'][s[i]-'A'] = g[s[i]-'A'][s[i-1]-'A'] = 1;
      }
    }
  }
  for(int i = 0; i < 26; i++) {
    for(int j = i+1; j < 26; j++) {
      for(int k = j+1; k < 26; k++) {
        for(int l = k+1; l < 26; l++) {
          for(int m = l+1; m < 26; m++) {
            if(solve(i, j, k, l, m)) return 0;
          }
        }
      }
    }
  }
  cout << "impossible\n";
}