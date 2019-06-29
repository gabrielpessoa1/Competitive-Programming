#include <bits/stdc++.h>
using namespace std;
 
const int ms = 1e5+5;
const double pi = acos(-1);
const double eps = 1e-6;
 
pair<double, int> ang[ms];
int cx[ms], cy[ms];
 
main() {
	int n, w, h;
	while(cin >> n >> w >> h, n || h || w) {
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			cx[i] = x;
			cy[i] = y;
			x = x + x - w;
			y = y + y - h;
			ang[i].second = i;
			ang[i].first = atan2(x, y);
			if(ang[i].first < 0) ang[i].first += pi + pi;
		}
		sort(ang, ang+n);
		for(int i = 0; i < n; i++) {
			ang[i+n] = ang[i];
			ang[i+n].first += pi + pi;
		}
		int lo = 0;
		int hi = 0;
		for(int i = 0; i < n; i++) {
			int lo = lower_bound(ang+i, ang+n+n, make_pair(ang[i].first+pi, -1)) - ang - i;
			int hi = lower_bound(ang+i, ang+n+n, make_pair(ang[i].first+pi, ms)) - ang - i;
			if(lo <= n/2 + 1 && hi >= n/2) {
				int start = i;
				if(lo == n/2 + 1) start = i +1;
				for(int j = start; j < start + n/2; j++) {
					int idx = ang[j].second;
					cout << cx[idx] << ' ' << cy[idx] << '\n';
				}
				break;
			}
		}
	}
}