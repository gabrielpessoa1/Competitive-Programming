#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1073676287, shift = 0xdefaced;

vector<char> st;
vector<int> wrds;
vector<int> wrdSz;
vector<int> supShft;
set<int> forb;
map<int, int> dicHash;
map<int, int> dicBeg;
map<int, int> dicEnd;
map<int, int> dicSz;

main() {
  #ifdef ONLINE_JUDGE
  freopen("kina.in", "r", stdin);
  freopen("kina.out", "w", stdout);
  #endif  
  char c, b = '0';
  int h = -1;
  int sup = 0;
  int ws = 0;
  while(true) {
    c = getchar();
    if(c == EOF) break;
    if(c >= 'a' && c <= 'z') {
      c += ('A'- 'a');
    }
    if(c >= 'A' && c <= 'Z') {
      if(h == -1) {
        b = c;
        h = c;
        sup = (' ' * shift + c) % mod;
        ws = 0;
      } else {
        h = (h * shift + c) % mod;
        sup = sup * shift % mod;
        ws++;
      }
    } else {
      if(h != -1) {
        wrds.push_back(h);
        st.push_back(b);
        supShft.push_back(sup);
        wrdSz.push_back(ws);
        h = -1;
      }
    }
  }
  if(h != -1) {
    wrds.push_back(h);
    st.push_back(b);
    supShft.push_back(sup);
    wrdSz.push_back(ws);
  }
  for(int i = 0; i < (int) wrds.size(); i++) {
    forb.insert(wrds[i]);
  }

  for(int i = 0; i < (int) wrds.size(); i++) {
    int ac = 0;
    int tot = 0;
    int totSz = 0;
    for(int j = i; j < (int) wrds.size(); j++) {
      ac = (ac * shift + st[j]) % mod;
      tot = (tot * supShft[j] + wrds[j]) % mod;
      totSz += wrdSz[j];
      if(forb.count(ac)) continue;
      if(!dicHash.count(ac)) {
        dicHash[ac] = tot;
        dicBeg[ac] = i;
        dicEnd[ac] = j;
        dicSz[ac] = -(j-i+1);
      } else if(dicHash[ac] != tot) {
        dicSz[ac] = 0;
        forb.insert(ac);
      } else if(dicEnd[ac] < i) {
        dicEnd[ac] = j;
        dicBeg[ac] = i;
        dicSz[ac] += totSz;
      }
    }
  }
  int ans = 0;
  int bestHash = -1;
  for(auto &p : dicSz) {
    if(p.second > ans) {
      ans = p.second;
      bestHash = p.first;
    }
  }
  cout << ans << endl;
  if(bestHash == -1) return 0;
  for(int i = dicBeg[bestHash]; i <= dicEnd[bestHash]; i++) {
    cout << st[i];
  }
  cout << '\n';
}