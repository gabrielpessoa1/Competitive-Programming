#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
 
const int ms = 110;
 
int l[ms], t[ms], r[ms], b[ms];
ii ds[ms][ms];
map<int, int> coordX, coordY;
int g[ms][ms];
 
 
ii dsFind(int i, int j) {
	if(ds[i][j] != make_pair(i, j)) ds[i][j] = dsFind(ds[i][j].first, ds[i][j].second);
	return ds[i][j];
}
 
int dsUnion(int i, int j, int a, int b) {
	ii x = dsFind(i, j);
	ii y = dsFind(a, b);
	ds[x.first][x.second] = y;
}
 
 
main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	while(cin >> n, n) {
		coordX.clear(); coordY.clear();
		memset(g, 0, sizeof g);
		for(int i = 0; i < n; i++) {
			cin >> l[i] >> t[i] >> r[i] >> b[i];
			coordX[l[i]] = 0; coordX[r[i]] = 0;
			coordY[t[i]] = 0; coordY[b[i]] = 0;
		}
		int xM = 0, yM = 0;
		for(auto &p : coordX) p.second = ++xM;
		for(auto &p : coordY) p.second = ++yM;
		for(int p = 0; p < n; p++) {
			int rig = coordX[r[p]], lef = coordX[l[p]];
			int up = coordY[t[p]], dow = coordY[b[p]];
			for(int i = lef; i < rig; i++) {
				for(int j = dow; j < up; j++) {
					g[i][j] |= (1ll << p);
				}
			}
		}
		xM++; yM++;
		for(int i = 0; i <= xM; i++) {
			for(int j = 0; j <= yM; j++) {
				ds[i][j] = {i, j};
				//cout << g[i][j] << ' ';
			}
			//cout << '\n';
		}
		for(int i = 0; i <= xM; i++) {
			for(int j = 0; j <= yM; j++) {
				if(g[i][j] == g[i+1][j] && i < xM) {
					dsUnion(i, j, i+1, j);
				}
				if(g[i][j] == g[i][j+1] && j < yM) {
					dsUnion(i, j, i, j+1);
				}
			}
		}
		int ans = 0;
		//cout <<dsFind(0, 0).first << ' ' << dsFind(0, 0).second << endl;
		for(int i = 0; i <= xM; i++) {
			for(int j = 0; j <= yM; j++) {
				if(dsFind(i, j) == make_pair(i, j)) {
					ans++;
					//cout << i << ' ' << j << " oi " << endl;
				}
			}
		}
		cout << ans << '\n';
	}
}