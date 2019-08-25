#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i) {
  int j = s.size() - 1;
  while(i < j) {
    if(s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}

main() {
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if(isPalindrome(s, i)) {
      for(int j = i-1; j >= 0; j--) {
        s.push_back(s[j]);
      }
      cout << s << endl;
      return 0;
    }
  }
}