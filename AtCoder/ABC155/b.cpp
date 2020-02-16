#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) { 
        cin >> a.at(i);
    }
    rep(i, n) {
        int num = a.at(i);
         
        if (!(num % 2)) {
            if (!( (!(num % 3) || !(num % 5)) )) {
                cout << "DENIED" << endl;
                exit(0);
            }
        }
    }   
    
    cout << "APPROVED" << endl;
    
    return 0;
}
