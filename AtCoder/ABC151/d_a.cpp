#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> s.at(i).at(j);
        }
    }
    
    int ans = 0;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s.at(i).at(j) == '.') {
                
                vector<vector<int>> visited(h, vector<int>(w, -1));
                //visited.at(i).at(j) = 0;

                queue<tuple<int, int, int>> q;
                q.push(make_tuple(i, j, visited.at(i).at(j)));
                
                while (!q.empty()) {
                    int y, x, count;
                    tie(y, x, count) = q.front();
                    q.pop();

                    if (visited.at(y).at(x) != -1) continue;

                    visited.at(y).at(x) = ++count;
                    ans = max(ans, visited.at(y).at(x));

                    if (y-1 >= 0 && s.at(y-1).at(x) == '.') {
                        q.push(make_tuple(y-1, x, count));
                    }
                    if (y+1 < h  && s.at(y+1).at(x) == '.') {
                        q.push(make_tuple(y+1, x, count));
                    }
                    if (x-1 >= 0 && s.at(y).at(x-1) == '.') {
                        q.push(make_tuple(y, x-1, count));
                    }
                    if (x+1 < w  && s.at(y).at(x+1) == '.') {
                        q.push(make_tuple(y, x+1, count));
                    }
                    
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

