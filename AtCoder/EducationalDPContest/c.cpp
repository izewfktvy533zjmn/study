#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> num(n, vector<int>(3));
    for (int i=0; i<n; i++) for (int j=0; j<3; j++) cin >> num[i][j];
    vector<vector<int>> dp(n+1, vector<int>(3, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (j == k) continue;
                if (dp[i+1][k] < dp[i][j] + num[i][k]) dp[i+1][k] = dp[i][j] + num[i][k];
            }
        }
    }

    int ans = 0;
    for (int i=0; i<3; i++) {
        if (ans < dp[n][i]) ans = dp[n][i];
    }

    cout << ans << endl;

    return 0;
}

