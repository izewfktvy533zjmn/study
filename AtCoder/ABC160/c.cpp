#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b(n);
    rep(i, n) {
        if (i == n-1) b[i] = k - a[i] + a[0];
        else b[i] = a[i+1] - a[i];
    }

    ll max_val = *max_element(b.begin(), b.end());
    ll sum_val = accumulate(b.begin(), b.end(), 0);
    ll ans = sum_val - max_val;

    cout << ans << endl;

    return 0;
}

