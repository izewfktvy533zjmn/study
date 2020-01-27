#include <bits/stdc++.h>

using namespace std;

int main() {
    long long h;
    cin >> h;

    double n = floor(log2(h));

    cout << (long long)pow(2, n+1)-1 << endl;
}

