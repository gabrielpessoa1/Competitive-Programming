#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9+7;

int mobius[ms];
int notPrime[ms];
int ans[ms];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        mobius[i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        if(!notPrime[i]) {
            for(int j = i; j <= n; j += i) {
                mobius[j] *= -1;
                notPrime[j] = 1;
            }
            for(int j = i*i; j <= n; j += i*i) {
                mobius[j] = 0;
            }
        }
        //cout << i << ' ' << mobius[i] << endl;
    }
    int realAns = 0;
    for(int i = 1; i <= n; i++) {
        int count = n/i;
        int sum = count*(count*i + i)/2;
        //cout << i << ' ' << sum << endl;
        for(int j = i; j <= m; j += i) {
            ans[j] += mobius[i] * (sum + count*j);
        }
    }
    for(int i = 1; i <= m ; i++) {
        realAns += ans[i];
    }
    cout << realAns << endl;
}