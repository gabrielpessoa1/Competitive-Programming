#include <bits/stdc++.h>
using namespace std;

vector<string> digits = {
"***   * *** *** * * *** *** *** *** ***",
"* *   *   *   * * * *   *     * * * * *",
"* *   * *** *** *** *** ***   * *** ***",
"* *   * *     *   *   * * *   * * *   *",
"***   * *** ***   * *** ***   * *** ***"};
string s[5];

bool equal(int a, int b) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 3; j++) {
      if(s[i][j+a] != digits[i][j+b]) return false;
    }
  }
  return true;
}

main() {
  for(int i = 0; i < 5; i++) {
    getline(cin, s[i]);
    //cout << s[i] << endl;
  }
  int n = 0;
  for(int i = 0; i < s[0].size(); i += 4) {
    int k = -1;
    for(int j = 0; j < 10; j++) {
      int w = j*4;
      if(equal(i, w)) k = j;
    }
    //cout << i << ' ' << k << endl;
    if(k == -1) {
      cout << "BOOM!!\n";
      return 0;
    }
    n = n * 10 + k;
  }
  if(n % 6) cout << "BOOM!!\n";
  else cout << "BEER!!\n";
}