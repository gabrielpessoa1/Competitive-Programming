// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// K - Kids' Entertainment
// https://codeforces.com/gym/101807/problem/K

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ii r[10] = {ii(1, 1), ii(-1, -1), ii(1, 0), ii(1, 1), ii(1, 1), ii(0, 1), ii(0, 1), ii(1, 1), ii(1, 1), ii(1, 1)};
ii l[10] = {ii(1, 1), ii(0, 0), ii(0, 1), ii(0, 0), ii(1, 0), ii(1, 0), ii(1, 1), ii(0, 0), ii(1, 1), ii(1, 0)};

int main() {
  int t;
  cin >> t;
  while(t--) {
   int i;
   cin >> i;
   int x = i/10;
   int y = i%10;
   int ans = c[x] + c[y];
   if(r[x].first == l[y].first && r[x].second == l[y].second) {
     ans -= r[x].first + r[x].second;
    }
    cout << ans << '\n';
  }
}