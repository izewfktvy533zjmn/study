#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> h(n+2);
    rep(i, n) cin >> h[i];
    vector<int> dp(n+2);
    rep(i, n) dp[i] = 1e9;
    dp[0] = 0;

    rep(i, n) {
        if (dp[i+1] > dp[i] + abs(h[i] - h[i+1])) dp[i+1] = dp[i] + abs(h[i] - h[i+1]);
        if (dp[i+2] > dp[i] + abs(h[i] - h[i+2])) dp[i+2] = dp[i] + abs(h[i] - h[i+2]);
    }
    
    cout << dp[n-1] << endl;
    
    return 0;
}

