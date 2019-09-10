#include <bits/stdc++.h>
using namespace std;
int main () {
  int n;
  cin >> n;
  string s, p;
  cin >> s >> p;
  if (n & 1) {
    for (int i = 0; i < s.size(); i++) {
      s[i] = !(s[i]-'0') + '0';
    }
  }
  cout << ((s == p) ? "Deletion succeeded" : "Deletion failed")  << endl;
}