#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> table(n, vector<char>(n, '-'));
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        table.at(a-1).at(b-1) = 'o';
        table.at(b-1).at(a-1) = 'x';
    }


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << table.at(i).at(j);
            if(j != n-1) cout << ' ';
        }
        cout << endl;
    }
}
