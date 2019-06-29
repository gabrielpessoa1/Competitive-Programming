#include <bits/stdc++.h>
using namespace std;
 
const int ms = 105;
 
int a[ms][3];
int t[ms][3];
int n, m;
 
main() {
	int g, temp;
	scanf("%d", &g);
	while(g--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < 3; j++) {
				scanf("%d", &a[i][j]);
			}
			scanf("%d", &temp);
		}
		bool end = 0;
		for(int i = 0; i < m && !end; i++) {
			for(int j = 0; j < 3 && !end; j++) {
				if(a[i][j] == 0) {
					cout << "INVALID: NULL RING\n";
					end = 1;
				}
			}
		}
		for(int i = 0; i < m && !end; i++) {
			for(int j = 0; j < 3 && !end; j++) {
				if(a[i][j] < -n || a[i][j] > n) {
					cout << "INVALID: RING MISSING\n";
					end = 1;
				}
			}
		}
		for(int i = 0; i < m && !end; i++) {
			for(int j = 0; j < 3 && !end; j++) {
				for(int k = j+1; k < 3 && !end; k++) {
					if(abs(a[i][j]) == abs(a[i][k])) {
						cout << "INVALID: RUNE CONTAINS A REPEATED RING\n";
						end = 1;
					}
				}
			}
		}
		if(end) continue;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < 3; j++) {
				if(a[i][j] < 0) t[i][j] = 0;
				else t[i][j] = 1;
				a[i][j] = abs(a[i][j])-1;
				//cout << a[i][j] << ' ' << t[i][j] << endl;
			}
		}
		bool sat = false;
		for(int i = 0; i < (1 << n) && !sat; i++) {
			bool valid = true;
			for(int j = 0; j < m && valid; j++) {
				bool p = false;
				for(int k = 0; k < 3 && !p; k++) {
					if(((bool)(i & (1 << a[j][k]))) == t[j][k]) p = true;
				}
				if(!p) valid = false;
			}
			if(valid) sat = true;
		}
		if(sat) cout << "RUNES SATISFIED!\n";
		else cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n";
	}
}