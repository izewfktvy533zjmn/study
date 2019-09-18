#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<long long> a;

    for (int i=0; i<n; i++) {
        int val;
        cin >> val;
        a.push(val);
    }
    
    for (int i=0; i<m; i++) {
        int max_val = a.top();
        a.pop();
        a.push(max_val/2);
    }

    long long sum_val = 0;

    for (int i=0; i<n; i++) {
        sum_val += a.top();
        a.pop();
    }

    cout << sum_val << endl;
}
