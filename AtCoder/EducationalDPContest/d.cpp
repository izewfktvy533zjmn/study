#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i=0; i<N; i++) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    dp[0][0] = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<=W; j++) {
            if (j - w[i] >= 0) {
                if (dp[i+1][j] < dp[i][j - w[i]] + v[i]) dp[i+1][j] = dp[i][j - w[i]] + v[i];
            }
            if (dp[i+1][j] < dp[i][j]) dp[i+1][j] = dp[i][j];
        }
    }
    
    cout << dp[N][W] << endl;

    return 0;
}

