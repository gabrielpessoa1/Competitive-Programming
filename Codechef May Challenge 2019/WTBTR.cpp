// May Challenge 2019
// WTBR - Where to Build the Roads
// https://www.codechef.com/MAY19B/problems/WTBR

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e4+5;

ll arr[2][ms];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            arr[0][i] = x+y;
            arr[1][i] = x-y;
        }
        ll dif = 1e15;
        sort(arr[0], arr[0]+n);
        sort(arr[1], arr[1]+n);
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j < n; j++) {
                dif = min(dif, arr[i][j]-arr[i][j-1]);
            }
        }
        cout << fixed << setprecision(15) << dif / 2.0 << '\n';
    }
}