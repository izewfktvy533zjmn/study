#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;

    bool flag = true;

    for (int i=0; i<s.size(); i++) {
        if (i % 2 == 0) {
            if (!(s.at(i) == 'R' || s.at(i) == 'U' || s.at(i) == 'D')) {
                flag = false;
                break;
            }
        }
        else {
            if (!(s.at(i) == 'L' || s.at(i) == 'U' || s.at(i) == 'D')) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}
