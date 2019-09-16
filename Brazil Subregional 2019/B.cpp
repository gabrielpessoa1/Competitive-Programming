#include <bits/stdc++.h>
using namespace std;

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int x;
    cin >> x;
    for(int i = 1; i < n; i++) {
        int y;
        cin >> y;
        if(y > x) {
            cout << "N\n";
            return 0;
        }
    }
    cout << "S\n";
}