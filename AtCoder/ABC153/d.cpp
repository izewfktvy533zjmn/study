#include <bits/stdc++.h>

using namespace std;

int main() {
    long long h;

    cin >> h;

    long long ans = pow(2, floor(log2(h)));
    cout << ans*2-1 << endl;
}

