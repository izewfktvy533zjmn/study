#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    string t = s;
    reverse(t.begin(), t.end());
    string s1 =  s.substr(0, ((n-1)/2));
    string t1 = s1;
    reverse(t1.begin(), t1.end());
    string s2 = s.substr(((n+3)/2)-1);
    string t2 = s2;
    reverse(t2.begin(), t2.end());

    if (s == t && s1 == t1 && s2 == t2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

