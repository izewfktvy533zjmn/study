#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        cout << (char)((s.at(i) + n - 65) % 26 + 65);
    }
    cout << endl;
}
