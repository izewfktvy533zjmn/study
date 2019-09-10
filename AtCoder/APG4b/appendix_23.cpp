#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(auto &ai : a) {
        cin >> ai;
    }

    map<int, int> table;

    for(auto &x : a) {
        if(table.count(x)) {
            table.at(x)++;
        }
        else {
            table[x] = 1;
        }
    }

    int ans_num = -1;
    int ans_count = -1;

    for(int &x : a) {
        if(ans_count < table.at(x)) {
            ans_num = x;
            ans_count = table.at(x);
        }
    }

    cout << ans_num << " " << ans_count << endl;
}
