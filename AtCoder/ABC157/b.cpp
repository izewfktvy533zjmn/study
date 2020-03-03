#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    vector<int> a1(3), a2(3), a3(3);
    vector<bool> f1(3, false), f2(3, false), f3(3, false);
    
    cin >> a1.at(0) >> a1.at(1) >> a1.at(2);
    cin >> a2.at(0) >> a2.at(1) >> a2.at(2);
    cin >> a3.at(0) >> a3.at(1) >> a3.at(2);
    
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b.at(i);
    
    rep(i, n) {
        rep(j, 3) {
            if (a1.at(j) == b.at(i)) f1.at(j) = true;
            if (a2.at(j) == b.at(i)) f2.at(j) = true;
            if (a3.at(j) == b.at(i)) f3.at(j) = true;
        }
    }

    if (f1.at(0) && f1.at(1) && f1.at(2)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (f2.at(0) && f2.at(1) && f2.at(2)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (f3.at(0) && f3.at(1) && f3.at(2)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (f1.at(0) && f2.at(0) && f3.at(0)) { 
        cout << "Yes" << endl;
        return 0;
    }
    if (f1.at(1) && f2.at(1) && f3.at(1)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (f1.at(2) && f2.at(2) && f3.at(2)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (f1.at(0) && f2.at(1) && f3.at(2)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (f1.at(2) && f2.at(1) && f3.at(0)) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
