#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    cout << (n * (n-1)) / 2 + (m * (m-1)) / 2 << endl;
    return 0;
}

