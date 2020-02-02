#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<string>> q(n, vector<string>(0));
    int p;
    string s;

    for (int i=0; i<m; i++) {
        cin >> p >> s;
        q.at(p-1).push_back(s);
    }
    
    int answer = 0;
    int penalty = 0;

    for (int i=0; i<n; i++) {
        int count = 0;

        for (int j=0; j<q.at(i).size(); j++) {
            if (q.at(i).at(j) == "AC") {
                answer++;
                penalty += count;
                break;
            }
            
            count++;
        }
    }

    cout << answer << " " << penalty << endl;

    return 0;

}


