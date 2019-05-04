// North America Qualifier 2018
// K - Run-Length Encoding, Run!
// https://open.kattis.com/problems/runlengthencodingrun

#include <bits/stdc++.h>
using namespace std;

int main() {
  string t, s;
  cin >> t >> s;
  if(t[0] == 'E') {
    char cur = '1';
    int qnt = 0;
    for(char c : s) {
      if(c == cur) qnt++;
      else {
        if(cur != '1') {
          cout << cur << qnt;
        }
        qnt = 1;
        cur = c;
      }
    }
    cout << cur << qnt << endl;
  } else {
    for(int i = 0; i < s.size(); i += 2) {
      for(int j = 0; j < s[i+1] - '0'; j++) {
        cout << s[i];
      }
    }
    cout << endl;
  }
}