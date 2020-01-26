#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<long long> p(n);
    for (int i=0; i<n; i++) {
        cin >> p.at(i);
    }

    long long min_val = p.at(0);
    long long counter = 1;

    for (int i=1; i<n; i++) {
        if (min_val >=  p.at(i)) {
            counter++;
            min_val = p.at(i);
        }
        
    }

    cout << counter << endl;
}

