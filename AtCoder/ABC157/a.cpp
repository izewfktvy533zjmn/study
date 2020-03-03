#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n % 2) {
        cout << n / 2 + 1 << endl;
    }
    else cout << n / 2 << endl;
    return 0;
}
