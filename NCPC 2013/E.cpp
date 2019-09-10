#include <bits/stdc++.h>
using namespace std;

string a, b;

int get() {
  for(int i = 0; i < min(a.size(), b.size()); i++) {
    if(a[i] != b[i]) {
      return i;
    }
  }
  return min(a.size(), b.size());
}

int main () {
  cin >> a >> b;
  int x = get();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int y = get();
  int top = min((int) a.size(), x+y);
  cout << max(0, (int) b.size() - top) << '\n';
}