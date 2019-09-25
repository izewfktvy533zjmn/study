#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int a, b;
    int sum = 1;
    int ans = 0;
    cin >> a >> b;
    
    while (b > sum) {
        sum--;
        sum += a;
        ans++;

    }

    cout << ans << endl;
}
