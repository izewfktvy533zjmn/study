#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> f(n, vector<int>(0));
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b; 
        f[a-1].push_back(b-1);
        f[b-1].push_back(a-1);
    }

    vector<vector<int>> b(n, vector<int>(0));
    for (int i=0; i<k; i++) {
        int c, d;
        cin >> c >> d;
        b[c-1].push_back(d-1);
        b[d-1].push_back(c-1);
    }
    
    map<int, int> gn;
    vector<int> g(n, 0);
    int num = 1;
    for (int i=0; i<n; i++) {
        if (!g[i]) {
            g[i] = num;
            int count = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int target = q.front();
                q.pop();
                for (int j=0; j<f[target].size(); j++) {
                    if (g[f[target][j]]) continue;
                    g[f[target][j]] = num;
                    count++;
                    q.push(f[target][j]);
                }
            }
            gn[num] = count;
            num++;
        }
    }
    
    for (int i=0; i<n-1; i++) {
        int bn = 0;
        for (int j=0; j<b[i].size(); j++) {
            if (g[i] == g[b[i][j]]) bn++;
        }
        //cout << gn[g[i]] << "-" << f[i].size() <<  "-" << bn <<  "-" <<  1 << " " ;
        //cout << gn[g[i]] - f[i].size() - bn - 1 << endl;
        cout << gn[g[i]] - f[i].size() - bn - 1 << " ";
    }
    int bn = 0;
    for (int j=0; j<b[n-1].size(); j++) {
        if (g[n-1] == g[b[n-1][j]]) bn++;
    }
    cout << gn[g[n-1]] -f[n-1].size() - bn - 1 << endl;

    return 0;
}

