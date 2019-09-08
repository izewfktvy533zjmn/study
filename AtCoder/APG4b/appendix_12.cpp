#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int sum = 1;

    for(int i=1; i<s.size()-1; i+=2) {
        if(s.at(i) == '+') {
            sum += 1;
        }
        else {
            sum -= 1;
        }
    }

    cout << sum << endl;
}
