#include <bits/stdc++.h>

using namespace std;


int main() {
    long long n;
    double sum = 0;
    cin >> n;

    vector<long long> x(n), y(n);
    for (int i=0; i<n; i++) {
        cin >> x.at(i) >> y.at(i);
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            sum += sqrt( pow( x.at(j) - x.at(i), 2) + pow( y.at(j) - y.at(i), 2));
        }
    }
    
    printf("%.10f\n", sum * 2 / n);
}
