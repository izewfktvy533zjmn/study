#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int y;
    cin >> y;
    
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (n < (i+j)) continue;
 
            int sum = ((n - i - j) * 10000) + (i * 1000) + (j * 5000);
 
            if (sum == y) {
                cout << (n-i-j) << " " << j << " " << i << endl;
                return 0;
            }
        }
    }
 
    cout << "-1 -1 -1" << endl;
    return 0;
}

