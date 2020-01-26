#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> h(n);
    for (int i=0; i<n; i++) {
        cin >> h.at(i);
    }
    
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());

    long long ret = 0;

    for (int i=k; i<n; i++) {
        ret += h.at(i);
    }
    
    cout << ret << endl;

}

