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
                visited.at(i).at(j) = 0;

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                
                while (!q.empty()) {
                    int y, x;
                    tie(y, x) = q.front();
                    q.pop();

                    if (y-1 >= 0 && s.at(y-1).at(x) == '.' && visited.at(y-1).at(x) == -1) {
                        q.push(make_pair(y-1, x));
                        visited.at(y-1).at(x) = visited.at(y).at(x) + 1;
                        ans = max(ans, visited.at(y-1).at(x));
                    }
                    if (y+1 < h  && s.at(y+1).at(x) == '.' && visited.at(y+1).at(x) == -1) {
                        q.push(make_pair(y+1, x));
                        visited.at(y+1).at(x) = visited.at(y).at(x) + 1;
                        ans = max(ans, visited.at(y+1).at(x));
                    }
                    if (x-1 >= 0 && s.at(y).at(x-1) == '.' && visited.at(y).at(x-1) == -1) {
                        q.push(make_pair(y, x-1));
                        visited.at(y).at(x-1) = visited.at(y).at(x) + 1;
                        ans = max(ans, visited.at(y).at(x-1));
                    }
                    if (x+1 < w  && s.at(y).at(x+1) == '.' & visited.at(y).at(x+1) == -1) {
                        q.push(make_pair(y, x+1));
                        visited.at(y).at(x+1) = visited.at(y).at(x) + 1;
                        ans = max(ans, visited.at(y).at(x+1));
                    }
                    
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

