#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9+7;

int clique[1 << 14];
int g[15][15];
int ans[1 << 14];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i < (1 << n); i++) {
        clique[i] = 1;
        for(int a = 0; a < n; a++) {
            if(i & (1 << a)) {
                for(int b = a + 1; b < n; b++) {
                    if((i & (1 << b)) && !g[a][b]) clique[i] = 0;
                }
            }
        }
    }
    ans[0] = 1;
    for(int i = 1; i < (1 << n); i++) {
        int k = -1;
        for(int j = 0; j < n; j++) if(i & (1 << j)) k = j;
        for(int s = i; s != 0; s = (s-1) & i) {
            if((s & (1 << k)) && clique[s]) ans[i] += ans[i ^ s];
        }
    }
    cout << ans[(1 << n) - 1] << endl;
}