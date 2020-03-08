#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
 
 
 
int main() {
    int a, b;
    cin >> a >> b;
    
    for (int i=2; i<1000000; i++) {
        int tax8 = floor(i * 0.08);
        int tax10 = floor(i * 0.1);
        if (tax8==a && tax10==b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}

