#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int a, b;
    cin >> a >> b;

    string u;
    cin >> u;
    
    map<string, int> m;
    m[s] = a;
    m[t] = b;

    if (u == s) {
        m[s]--;
    }
    else {
        m[t]--;
    }

    cout << m[s] << " " << m[t] << endl;

    return 0;

}

