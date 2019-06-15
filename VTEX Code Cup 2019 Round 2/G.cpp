#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;

string s;
int idx;
vi g[ms];
int vis[ms];
int deg[ms];
int goTo[ms][20];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(int v : g[u]) {
        dfs(v);
    }
    if(g[u].empty()) goTo[u][0] = u;
    else goTo[u][0] = g[u][0];
    for(int i = 1; i < 20; i++) {
        goTo[u][i] = goTo[goTo[u][i-1]][i-1];
    }
}

int getVal() {
    if(idx == s.size() || s[idx] < '0' || s[idx] > '9') return 1;
    int cur = 0;
    while(!(idx == s.size() || s[idx] < '0' || s[idx] > '9')) {
        cur = cur * 10 + (s[idx] - '0');
        idx++;
    }
    return cur;
}

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> deg[i];
        g[i].resize(deg[i]);
        for(int j = 0; j < deg[i]; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        dfs(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int p;
        cin >> p >> s;
        //cout << p << ' ' << s << endl;
        idx = 0;
        while(idx < s.size()) {
            if(s[idx] == '~') {
                idx++;
                int k = getVal();
                //cout << "DBG ~ " << k << endl;
                for(int i = 19; i >= 0; i--) {
                    if((1 << i) <= k) {
                        k -= (1 << i);
                        p = goTo[p][i];
                    }
                }
            } else {
                idx++;
                int k = getVal();
                //cout << "DBG ^ " << k << endl;
                p = g[p][k-1];
            }
        }
        cout << p << endl;
    }
}