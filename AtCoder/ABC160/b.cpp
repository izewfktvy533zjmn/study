#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll x;
    cin >> x;

    ll a = x / 500;
    ll b = (x-a*500) / 5;

    cout << a*1000 + b*5 << endl;

    return 0;
}

