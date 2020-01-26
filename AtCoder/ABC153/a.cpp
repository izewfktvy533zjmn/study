#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, a;
    cin >> h >> a;
    
    if (h%a) {
        cout << h/a + 1 << endl;
    }
    else {
        cout << h/a << endl;
    }

}

