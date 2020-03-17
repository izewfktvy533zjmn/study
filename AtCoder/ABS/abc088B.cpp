#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i=0;i<n;i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    int alice = 0;
    int bob = 0;
    bool flag = true;
    while (!pq.empty()) {
        if (flag) alice += pq.top();
        else bob += pq.top();
        pq.pop();
        flag = !flag;
    }


    cout << alice - bob << endl;

}
