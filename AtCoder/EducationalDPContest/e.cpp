#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for (int i=0; i<N; i++) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(N+1, vector<ll>(100100, 1e12));
    dp[0][0] = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<100100; j++) {
            if (j - v[i] >= 0) {
                if (dp[i+1][j] > dp[i][j - v[i]] + w[i]) dp[i+1][j] = dp[i][j - v[i]] + w[i];
            }

            if (dp[i+1][j] > dp[i][j]) dp[i+1][j] = dp[i][j];
        }
    }
    
    ll ans = 0;
    for (int j=0; j<100100; j++) {
        if (dp[N][j] <= W) ans = j;
    }

    cout << ans << endl;

    return 0;
}

