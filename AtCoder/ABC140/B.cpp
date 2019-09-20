#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }

    vector<int> b(n);
    for (int i=0; i<n; i++) {
        cin >> b.at(i);
    }

    vector<int> c(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> c.at(i);
    }

    int satisfied=0;
    int pre=a.at(0);
    for (int i=0; i<n; i++) {
        satisfied += b.at(a.at(i)-1);
        
        if (a.at(i) - pre == 1) {
            satisfied += c.at(pre-1);
        }

        pre = a.at(i);
    }

    cout << satisfied << endl;
}
