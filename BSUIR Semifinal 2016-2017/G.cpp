// BSUIR Semifinal 2016-2017
// G - Many dimensional dice
// https://codeforces.com/gym/102134/problem/G

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	double e = 0;
	long long l = 0;
	while(n > 0) {
		long long lo = 1, hi = n;
		while(lo < hi) {
			long long mi = (lo+hi)/2;
			double prob = pow(1.0 * l / k, mi);
			long long tempE = prob * e + (1 - prob) * (1 + l + k) / 2.0;
			if(tempE > l) hi = mi;
			else lo = mi + 1;
		}
		double prob = pow(1.0 * l / k, lo);
		e = prob * e + (1 - prob) * (1 + l + k) / 2.0;
		l = e;
		n -= lo;
	}
	cout << setprecision(12) << e << '\n';
}
