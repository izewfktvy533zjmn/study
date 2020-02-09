#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<long long, bool> m;
    vector<long long> a(n);

    for(int i=0; i<n; i++) {
        cin >> a.at(i);
    }

    for(int i=0; i<n; i++) {
        long long key = a.at(i);

        if (m.count(key)) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            m[key] = true;
        }
    }

    cout << "YES" << endl;

    return 0;
}

