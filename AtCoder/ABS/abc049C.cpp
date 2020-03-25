#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> words = { "dream", "dreamer", "erase", "eraser" };
    
    for (int i=0; i<4; i++) reverse(words[i].begin(), words[i].end());
    reverse(s.begin(), s.end());

    
    for (int i=0; i<s.size(); i++) {
        bool flag = true;

        for (int j=0; j<4; j++) {
            if (s.substr(i, words[j].size()) == words[j]) {
                flag = false;
                i += words[j].size()-1;
                break;
            }
        }
        
        if (flag) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;

}

