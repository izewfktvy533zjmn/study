#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
 
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll c = a + b;
    ll ans = a * (n/c);
    ans += min(n%c, a);
    cout << ans << endl;
    
    return 0;
}

