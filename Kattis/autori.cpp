// KATTIS
// autori - Autori
// https://open.kattis.com/problems/autori

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for(char c : s) {
    if(c >= 'A' && c <= 'Z') cout << c;
  }
  cout << endl;
}