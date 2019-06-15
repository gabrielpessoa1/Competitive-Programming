#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef pair<int, int> ii;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;

int n;
int arr[ms];
int ans1[ms];
int ans2[ms];

void solve(int arr[], int ans[]) {
    ans[0] = 0;
    stack<ii> s;
    for(int i = 1; i <= n; i++) {
        ii toInsert = {arr[i-1], 1};
        ans[i] = ans[i-1];
        while(!s.empty() && toInsert.first <= s.top().first) {
            toInsert.second += s.top().second;
            ans[i] += (s.top().first - toInsert.first) * s.top().second;
            s.pop();
        }
        s.push(toInsert);
    }
}

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(arr, ans1);
    reverse(arr, arr+n);
    solve(arr, ans2);
    int ans = inf;
    for(int i = 0; i <= n; i++) {
        ans = min(ans, ans1[i] + ans2[n-i]);
    }
    cout << ans << endl;
}