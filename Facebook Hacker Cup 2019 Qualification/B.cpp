#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  string s;
  for(int T = 1; T <= t; T++) {
    cin >> s;
    int emp = 0, b = 0;
    for(char c : s) {
      emp += c == '.';
      b += c == 'B';
    }
    cout << "Case #" << T << ": ";
    if(emp > 0 && (b >= 2 || (b == 1 && emp == 1))) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
  }
}