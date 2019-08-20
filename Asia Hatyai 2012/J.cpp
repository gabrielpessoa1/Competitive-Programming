#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  string ans = "";
  string cur = "";
  while(true) {
    char c = getchar();
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-') {
      cur.push_back(c);
    } else {
      if(cur == "E-N-D") {
        for(auto &c : ans) c = tolower(c);
        cout << ans << endl;
        return 0;
      } else {
        if(cur.size() > ans.size()) ans = cur;
        cur = "";
      }
    }
  }
}