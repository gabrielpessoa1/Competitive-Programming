#include <bits/stdc++.h>
using namespace std;
 
main() {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	while(m--) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << sum % n << '\n';
}