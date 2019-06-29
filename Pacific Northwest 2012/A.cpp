#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<int> good = {1, 2, 3, 3, 4, 10};
vector<int> evil = {1, 2, 2, 2, 3, 5, 10};
 
main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Battle " << t << ": ";
		int g = 0, e = 0;
		for(int i = 0; i < good.size(); i++) {
			int x;
			cin >> x;
			g += x * good[i];
		}
		for(int i = 0; i < evil.size(); i++) {
			int x;
			cin >> x;
			e += x * evil[i];
		}
		if(g > e) cout << "Good triumphs over Evil\n";
		else if(g < e) cout << "Evil eradicates all trace of Good\n";
		else cout << "No victor on this battle field\n";
	}
}