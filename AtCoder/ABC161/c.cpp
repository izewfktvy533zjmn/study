#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;


    if ( abs(n-k) > n) {
        cout << n << endl;
    }
    else if (n == k) {
        cout << 0 << endl;
    }
    else {
        n = n % k;

        if ( abs(n-k) > n) {
            cout << n << endl;
        }
        else if (n == k) {
            cout << 0 << endl;
        }
        else {
            cout << abs(n-k) << endl;
        }
    }

    
    
    return 0;
}

