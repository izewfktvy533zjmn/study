#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k, q;
    cin >> n >> k >> q;

    int a;
    vector<int> mp(n, k-q);

    
    for (int i=0; i<q; i++) {
        cin >> a;
        mp.at(a-1)++;
    }

    for (auto p: mp) {
        if (p <= 0) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }

}
