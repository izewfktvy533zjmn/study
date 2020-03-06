#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> a(M);
    for (int i=0; i<M; i++) cin >> a[i].first >> a[i].second;
    
    for (int x=0; x<1000; x++) {
        int keta = 1;
        int nx = x/10;
        vector<int> d(1, x%10);

        while (nx) {
            keta++;
            d.push_back(nx%10);
            nx /= 10;
        }

        reverse(d.begin(), d.end());

        if (keta != N) continue;

        bool ok = true;

        for (int i=0; i<M; i++) {
            if (d[a[i].first-1] != a[i].second) ok = false;
        }

        if (ok) {
            cout << x << endl;
            return 0;
        }

    }
    
    cout << -1 << endl;

    return 0;
}

