// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// D - Differentiation
// https://codeforces.com/gym/101807/problem/D

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int look = 0;
string s;

int getRealNumber() {
  if(look == s.size() || s[look] < '0' || s[look] > '9') {
    return 1;
  }
  int x = s[look] - '0';
  look++;
  if(look < s.size() && s[look] >= '0' && s[look] <= '9') return x * 10 + getRealNumber();
  else return x;
}

int getNumber() {
  int temp = 1;
  if(s[look] == '+' || s[look] == '-') {
    if(s[look] == '-') temp = -1;
    look++;
  }
  return getRealNumber() * temp;
}

void getTerm(bool first) {
  int ans = 1;
  int x = getNumber();
  if(look < s.size()) {
   look++;
   int y = getRealNumber();
   x = x*y;
   y--;
   if(x > 0 && !first) cout << '+';
   if(x == -1) cout << '-';
   else if(x != 1) cout << x;
   if(y != 0) {
    cout << 'x';
    if(y != 1) cout << y;  
   } else if(x == 1 || x == -1) {
    cout << 1;
   }
  }
}

int main() {
  cin >> s;
  if(s.size() == 1 && s[0] >= '0' && s[0] <= '9') {
    cout << 0 << endl;
    return 0;
  }
  if(s.size() == 2 && s[0] >= '0' && s[0] <= '9' && s[1] >= '0' && s[1] <= '9') {
    cout << 0 << endl;
    return 0;
  }
  if(s.size() == 2 && s[0] == '-' && s[1] >= '0' && s[1] <= '9') {
    cout << 0 << endl;
    return 0;
  }
  if(s.size() == 3 && s[0] == '-' && s[2] >= '0' && s[2] <= '9' && s[1] >= '0' && s[1] <= '9') {
    cout << 0 << endl;
    return 0;
  }
  bool first = true;
  while(look < s.size()) {
    getTerm(first);
    first = false;    
  }
  cout << '\n';
}