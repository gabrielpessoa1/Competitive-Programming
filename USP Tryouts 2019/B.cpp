#include <bits/stdc++.h>
using namespace std;

string s;
int pos;
char cur;

void fail() {
  cout << "NO\n";
  exit(0);
}

void next() {
  if(pos == s.size()) fail();
  do {
    cur = s[pos++];
  } while(cur == ' ');
}

void M();

bool isDigit(char c) {
  return c >= '0' && c <= '9';
}

void I() {
  if(!isDigit(cur)) fail();
  while(isDigit(s[pos])) {
    pos++;
  }
  next();
}

void T() {
  if(cur == '{') {
    next();
    M();
    if(cur != '}') fail();
    next();
  } else {
    I();
  }
}

void p() {
  if(cur == ':') {
    next();
    T();
    p();
  }
}

void P() {
  T();
  p();
}

void m() {
  if(cur == '|') {
    next();
    P();
    m();
  }
}

void M() {
  if(cur == '$') {
    next();
    if(cur != '|') fail();
    next();
    P();
    m();
  } else if(cur == '|') {
    next();
    M();
    m();
  } else {
    P();
    m();
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  getline(cin, s);
  s.push_back('_');
  cur = s[0];
  pos++;
  M();
  if(cur != '_') fail();
  cout << "YES\n";
  return 0;
}