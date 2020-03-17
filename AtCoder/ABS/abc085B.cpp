#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> d;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        d.insert(num);
    }
    cout << d.size() << endl;

    return 0;
}

