#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;

    for (int i=1; i<=n; i++) {
        int sum = 0;
        int t = i;
        for (int j=0; j<5; j++) {
            sum += t%10;
            t /= 10;
        }
        if ( (a <= sum) && (sum <= b) ) ans += i;
    }
    cout << ans << endl;

    return 0;
}

