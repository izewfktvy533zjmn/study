#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    bool rev = false;
    deque<char> dq;

    for (int i=0; i<s.size(); i++) dq.push_back(s[i]);

    for (int i=0; i<q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            rev = !rev;
        }
        else {
            int f;
            char c;
            cin >> f >> c;

            if (f == 1) {
                if (!rev) dq.push_front(c);
                else dq.push_back(c);
            }
            else {
                if (!rev) dq.push_back(c);
                else dq.push_front(c);
            }
        }
    }
    
    if (!rev) {
        for (int i=0; i<dq.size(); i++) {
            cout << dq.at(i);
        }
        cout << endl;
    }
    else {
        for (int i=0; i<dq.size(); i++) {
            cout << dq.at(dq.size()-i-1);
        }
        cout << endl;
    }
    
    return 0;
}
