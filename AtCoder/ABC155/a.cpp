#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    set<int> ans;
    ans.insert(a);
    ans.insert(b);
    ans.insert(c);

    if (ans.size() == 2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
