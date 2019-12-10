#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int count_digits(ll num) {
    int digits = 0;

    while (num != 0) {
        num /= 10;
        digits++;
    }

    return digits;
}


int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    ll l=0, r=1000000001;

    while (r-l > 1) {

        ll n = (l+r)/2;

        if ( (a*n) + (b*count_digits(n)) <= x) {
            l = n;
        }
        else {
            r = n;
        }
    }

    cout << l << endl;

}

