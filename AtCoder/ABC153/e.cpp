#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, n;
    cin >> h >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    vector<int> dp(h+1);
     
    for (int i=0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
    }
    

    for (int i=1; i<=h; i++) {
        dp.at(i) = 1e9;

        for (int j=0; j<n; j++) {
            dp.at(i) = min(dp.at(i), dp.at(max(0, i - a[j])) + b[j]);
        }
    }

    int ans = dp[h];

    cout << ans << endl;


    return 0;

}

