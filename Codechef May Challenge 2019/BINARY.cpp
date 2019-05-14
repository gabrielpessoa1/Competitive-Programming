// May Challenge 2019
// BINARY - Binary Movements
// https://www.codechef.com/MAY19B/problems/BINARY

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e6+5;

int a[ms];
int q[ms];
int front, tail;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, z;
        cin >> n >> z;
        stack<int> s;
        front = 0; tail = 0;
        for(int i = 0; i < z; i++) {
            q[i] = 0;
            s.push(i);
        }
        tail = z;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1) {
                swap(a[i], a[i-cur]);
                cur -= q[front++];
                s.push(tail);
                q[tail++] = 0;
            } else {
                if(!s.empty()) {
                    q[s.top()] = 1;
                    if(s.top() >= front) cur++;
                    s.pop();
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << a[i];
            if(i != n - 1) cout << ' ';
        }
        cout << '\n';
    }
}