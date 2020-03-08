#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag = false;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'h' && !flag) {
            flag = true;
        }
        else if (s[i] == 'i' && flag) {
            flag = false;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }

    if (flag) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}

