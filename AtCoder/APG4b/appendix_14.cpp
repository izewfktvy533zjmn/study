#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int max_val = max(a, b);
    max_val = max(c, max_val);

    int min_val = min(a, b);
    min_val = min(c, min_val);

    cout << max_val - min_val << endl;
}
