#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    
    vector<ll> b(n-1);
    for (int i=0; i<n-1; i++) {
        cin >> b.at(i);
    }

    vector<ll> a(n, 1000000);
    for (int i=0; i<n-1; i++) {
        if (a.at(i) > b.at(i)) {
            a.at(i) = b.at(i);
        }
        if (a.at(i+1) > b.at(i)) {
            a.at(i+1) = b.at(i);
        }
    }

    cout << accumulate(a.begin(), a.end(), 0) << endl;
   
}
