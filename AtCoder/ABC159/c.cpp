#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int l;
    cin >> l;
    long double ans = 0;
    
    if (l < 10) {
        for (long double i=0.001; i<l; i+=0.001) {
            
            for (long double j=0.001; j<l; j+=0.001) {
                if (l <= i+j) continue;
                if (ans < (l-(i+j))*i*j) ans = (l-(i+j))*i*j;
            }
        }
    }

    else if (l < 100) {
        for (long double i=0.01; i<l; i+=0.01) {
            
            for (long double j=0.01; j<l; j+=0.01) {
                if (l <= i+j) continue;
                if (ans < (l-(i+j))*i*j) ans = (l-(i+j))*i*j;
            }
        }
    }

    else {
        for (long double i=0.1; i<l/2; i+=0.1) {
            for (long double j=0.1; j<l/2; j+=0.1) {
                if (l <= i+j) continue;
                if (ans < (l-(i+j))*i*j) ans = (l-(i+j))*i*j;
            }
        }
    }


    printf("%.12Lf\n", ans);
    return 0;
}

