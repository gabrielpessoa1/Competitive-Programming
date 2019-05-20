#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int val[300];
vector<char> iVal = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int i = 0; i < 11; i++) val[iVal[i]] = i;
  while(t--) {
    string s;
    int k;
    cin >> k >> s;
    vector<int> a, b;
    for(char ch : s) {
      a.push_back(val[ch]);
    }
    while(k > 0) {
      b.push_back(k%11);
      k /= 11;
    }
    reverse(a.begin(), a.end());
    int n = a.size();
    while(b.size() < a.size()) b.push_back(0);
    while(a.size() < b.size()) a.push_back(0);
    vector<int> c;
    int carry = 0;
    for(int i = 0; i < a.size(); i++) {
      c.push_back((a[i] + b[i] + carry) % 11);
      carry = (a[i] + b[i] + carry) / 11;
    }
    if(carry) c.push_back(carry);
    c.push_back(0);
    for(int i = n; i < c.size(); i++) {
      bool achou = 0;
      for(int j = i; j < c.size(); j++) {
        if(c[j] > 0) {
          achou = 1;
          c[j]--;
          for(int k = j-1; k >= i; k--) {
            c[k] = 10;
          }
          break;
        }
      }
      if(!achou) {
        for(int j = i - 1; j >= 0; j--) {
          cout << iVal[c[j]];
        }
        cout << '\n';
        break;
      }

    }
  }
}