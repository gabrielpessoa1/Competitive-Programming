// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// F - Final Fixture
// https://codeforces.com/gym/101807/problem/F

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 1e5+5;

int n;
int arr[ms];
pair<int, int> matches[ms];

int main() {
  cin >> n;
  for(int i = 0; i < n/2; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    matches[i] = {u, v};
  }
  for(int i = 0; i < n; i++) {
    int s, c;
    cin >> arr[i] >> s >> c;
  }
  for(int i = 0; i < n; i++) {
    int posBoa = 1, posRuim = 1;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(arr[j] + 3 >= arr[i]) posRuim++;
      if(arr[j] - 3 > arr[i]) posBoa++;
    }
    for(int j = 0; j < n/2; j++) {
      int u = matches[j].first;
      int v = matches[j].second;
      if((arr[u] == arr[i]+3 || arr[v] == arr[i]+3) && (arr[v] > arr[i] && arr[v] <= arr[i] + 3 && arr[u] > arr[i] && arr[u] <= arr[i] + 3)) posBoa++;
      if(arr[u] < arr[i] && arr[u] >= arr[i]-3 && arr[v] < arr[i] && arr[v] >= arr[i]-3 && (arr[u] != arr[i] - 1 || arr[v] != arr[i] - 1)) posRuim--;
    }
    cout << posBoa << ' ' << posRuim << '\n';
  }
}