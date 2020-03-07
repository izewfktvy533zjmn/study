#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<set<int>> is(26);
    for (int i=0; i<n; i++) is[s[i]-'a'].insert(i);
    for (int qi=0; qi<q; qi++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int i;
            char c;
            cin >> i >> c;
            --i;
            is[s[i]-'a'].erase(i);
            s[i] = c;
            is[s[i]-'a'].insert(i);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l;
            int ans = 0;
            for (int i=0; i<26; i++) {
                auto it = is[i].lower_bound(l);
                if (it != is[i].end() && *it < r) ++ans;
            }
            
            cout << ans << endl;
        }
    }

    return 0;
}

