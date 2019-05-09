// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// E - Error
// https://codeforces.com/gym/101807/problem/E

#include <bits/stdc++.h>
using namespace std;

const int ms = 11;

int arr[ms];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  sort(arr, arr+n);
  do {
    int sum = 0;
    bool invalid = false;
    for(int i = 0; i < n; i++) {
      sum += arr[i];
      if(sum >= 1e8 || sum < 0) {
        invalid = true;
      }
    }
    if(!invalid) {
     for(int i = 0; i < n; i++) {
      cout << arr[i] << '\n';
     }
     return 0;
    }
  } while(next_permutation(arr, arr+n));
  cout << "Error\n";
}