#include <bits/stdc++.h>

using namespace std;


int main() {
    long long n;
    cin >> n;

    vector<long long> h(n);
    for (int i=0; i<n; i++) {
        cin >> h.at(i);
    }

    int ans = 0;
    int cnt = 0;
    int now = h.at(0);
    for (int i=1; i<n; i++) {
        if (now >= h.at(i)) {
            now = h.at(i);
            cnt++;
        }
        else {
            if (ans < cnt) {
                ans = cnt;
            }
            cnt = 0;
            now = h.at(i);
        }
    }
    if (ans < cnt) {
        ans = cnt;
    }
    

    cout << ans << endl;
}
