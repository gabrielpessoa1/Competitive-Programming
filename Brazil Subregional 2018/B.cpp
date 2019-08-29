#include <bits/stdc++.h>
using namespace std;

int n, m;

int nim[101][101];
int step[205];
int t = 0;

int main() {
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			if(i == j) continue;
			++t;
			for(int k = 1; k < i; k++) {
				if(k != j) step[nim[k][j]] = t;
			}
			for(int k = 1; k < j; k++) {
				if(k != i) step[nim[i][k]] = t;
			}
			for(int k = 1; k < min(i, j); k++) {
				step[nim[i-k][j-k]] = t;
			}
			for(nim[i][j] = 0; step[nim[i][j]] == t; nim[i][j]++);
		}
	}
	int n;
	cin >> n;
	int ans = 0;
	while(n--) {
		int x, y;
		cin >> x >> y;
		if(x == y) {
			cout << "Y\n";
			return 0;
		}
		ans ^= nim[x][y];
	}
	if(ans) cout << "Y\n";
	else cout << "N\n";
}