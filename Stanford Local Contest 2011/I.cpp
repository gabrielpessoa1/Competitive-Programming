#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 5005;
const double pi = acos(-1);
const double eps = 1e-6;
 
string s[ms];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
main() {
  int n;
  while(cin >> n, n) {
    for(int i = 0; i < n; i++) cin >> s[i];
    bool possible = true;
    for(int t = 0; t < 200; t++) {
      double x = uniform_real_distribution<double>(0, pi/2 - eps)(rng);
      for(int qd = 0; qd < 4; qd++) {
        stack<double> st;
        for(int i = 0; i < n; i++) {
          if(s[i] == "x") st.push(x);
          else if(s[i].size() == 1) {
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            if(s[i] == "+") st.push(a+b);
            else if(s[i] == "-") st.push(b-a);
            else if(s[i] == "*") st.push(a*b);
          } else {
            double a = st.top(); st.pop();
            if(s[i] == "sin") st.push(sin(a));
            else if(s[i] == "cos") st.push(cos(a));
            else {
              if(tan(a) > 1e15) {
                st.push(0);
                break;
              }
              st.push(tan(a));
            }
          } 
          //cout << "O topo ficou " << st.top() << endl;
        }
        //cout << x << ": " << st.top() << endl;
        if(abs(st.top()) > eps) possible = false;
        x += pi/2;
      }
    }
    if(possible) cout << "Identity\n";
    else cout << "Not an identity\n";
  }
}