#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll h, w;
    cin >> h >> w;

    ll a, b;

    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    if (h%2) {
        a = h/2 + 1;
        b = h/2;
    }
    else {
        a = h/2;
        b = h/2;
    }

    if (w%2) {
        if (w == 1) {
            cout << a << endl;
        }
        else {
            cout << (a+b) * (w/2) + a << endl;
        }
    }
    else {
        cout << (a+b) * (w/2)<< endl;
    }
            
    return 0;
}

