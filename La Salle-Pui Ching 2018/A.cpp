// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// A - Ambidexterity
// https://codeforces.com/gym/101807/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, r, p;
  cin >> l >> r >> p;
  bool right = false;
  if(r > l) {
   right = true;
   swap(l, r);
  }
  if(r * 100 >= p * l) {
    cout << "Ambidextrous" << '\n';
  } else if(right) {
    cout << "Right-handed" << '\n';
  } else {
    cout << "Left-handed" << '\n';
  }
}