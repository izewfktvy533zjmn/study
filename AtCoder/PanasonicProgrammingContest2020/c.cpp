#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;


int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    
    if (a + (2 * sqrtl((long double)a) * sqrtl((long double)b)) + b < c) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

