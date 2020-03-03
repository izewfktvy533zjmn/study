#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> dp(n+k);
    rep(i, n+k) dp[i] = 1e9;
    dp[0] = 0;

    rep(i, n) {
        for (int j=1; j<=k; j++) {
            if (dp[i+j] > dp[i] + abs(h[i] - h[i+j])) dp[i+j] = dp[i] + abs(h[i] - h[i+j]);
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}

