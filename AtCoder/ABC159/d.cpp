#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;    
    vector<ll> a(n);
    map<ll, ll> m;
    rep(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }

    ll sum = 0;
    rep(i, n+1) {
        if (m[i] > 0) sum += ((m[i] * (m[i]-1)) / 2);
    }
    rep(i, n) {
        cout << sum-m[a[i]]+1 << endl;
    }

    return 0;
}

