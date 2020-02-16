#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> dict;
    set<string> st;

    rep(i, n) {
        cin >> s.at(i);
        st.insert(s.at(i));
        dict[s.at(i)] = 0;
    }
    
    rep(i, n) {
        dict[s.at(i)]++;
    }
    
    vector<pair<int, string>> tmp;
    for (string str: st) {
        tmp.push_back(make_pair(dict[str], str));
    }
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());

    stack<string> ans;
    string str;
    int max_count;
    tie(max_count, str) = tmp.at(0);
    ans.push(str);

    for (int i=1; i<tmp.size(); i++) {
        string str;
        int count;
        tie(count, str) = tmp.at(i);

        if (count == max_count) {
            ans.push(str);
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}
