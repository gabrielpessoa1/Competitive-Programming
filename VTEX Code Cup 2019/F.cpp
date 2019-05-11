// VTEX Code Cup 2019
// F - Gift Box
// https://vtexcc19.kattis.com/problems/vtexcc19.giftbox

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 0x3f3f3f3f;
const int ms = 2e5+5;
const int mod = 1e9+7;

vector<int> arr[ms];

main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    arr[i] = vector<int>(3);
    for(int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
    sort(arr[i].begin(), arr[i].end());
  }
  sort(arr, arr+n);
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      if(arr[i][j] <= arr[i-1][j]) {
        cout << "N\n";
        return 0;
      }
    }
  }
  cout << "S\n";
  return 0;
}