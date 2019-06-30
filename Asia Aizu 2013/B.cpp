#include <bits/stdc++.h>
using namespace std;
 
int n, l;
int p[30];
int d[30];
int tempoSaida[30];
 
main() {
	cin.tie(0); ios::sync_with_stdio(0);
	while(cin >> n >> l, n || l) {
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s >> p[i];
			d[i] = s[0] == 'R';
		}
		int t = 0;
		int ants = n;
		while(ants > 0) {
			++t;
			ants = 0;
			for(int i = 0; i < n; i++) {
				if(p[i] > 0 && p[i] < l) {
					if(d[i]) p[i]++;
					else p[i]--;
					tempoSaida[i] = t;
				}
				if(p[i] > 0 && p[i] < l) ants++;
			}
			//cout << ants << ' ' << t << " dbg " << endl;
			for(int i = 0; i < n; i++) {
				for(int j = i+1; j < n; j++) {
					if(p[i] > 0 && p[i] < l && p[i] == p[j]) {
						swap(d[i], d[j]);
					}
				}
			}
		}
		pair<int, pair<int, int>> ans = {-1, {0, 0}};
		for(int i = 0; i < n; i++) {
			ans = max(ans, make_pair(tempoSaida[i], make_pair((int) !d[i], i)));
		}
		cout << ans.first << ' ' << ans.second.second + 1<< '\n'; 
	}
}