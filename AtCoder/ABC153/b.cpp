#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, n;
    cin >> h >> n;

    int a;
    int sum_val = 0;
    for (int i=0; i<n; i++) {
        cin >> a;
        sum_val += a;
    }

    if (h <= sum_val) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}

