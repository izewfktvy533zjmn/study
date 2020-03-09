#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    bool flag = false;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]%2 == 1) flag = true;
    }

    long long count = 0;

    while (!flag) {
        for (int i=0; i<n; i++) {
            if (a[i]%2 == 1) {
                flag = true;
                break;
            }
            else a[i] /= 2;
        }
        if (!flag) count++;
    }

    cout << count << endl;

    return 0;
}

