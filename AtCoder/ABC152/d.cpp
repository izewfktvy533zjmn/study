#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(10, vector<int>(10));

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            c.at(i).at(j) = 0;
        }
    }

    for (int i=1; i<=n; i++) {
        int num = i;
        int head;
        int tail = i % 10;

        if (tail == 0) continue;

        while (num) {
            head = num;
            num = num / 10;
        }

        //cout << head << " " << tail << endl;

        c.at(head-1).at(tail-1)++;
    }

    long long ans = 0;
    
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            ans += c.at(i).at(j) * c.at(j).at(i);
        }
    }

    cout << ans << endl;

    return 0;
}
