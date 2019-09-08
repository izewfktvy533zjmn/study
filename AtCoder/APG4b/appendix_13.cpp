#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a.at(i);
    }

    int avg = accumulate(a.begin(), a.end(), 0) / n;

    for(int i=0; i<n; i++) {
        cout << abs(avg - a.at(i)) << endl;
    }
}
