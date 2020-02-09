#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    vector<double> v(n, 0);

    for (int i=0; i<n; i++) {
        cin >> p.at(i);

        for (int j=1; j<=p.at(i); j++) {
            v.at(i) += j;
        }
        v.at(i) /= p.at(i);
    }
    
   
    double sum_v = 0;
    double max_sum_v = 0;
    for (int i=0; i<k; i++) {
        sum_v += v.at(i);
    }
    max_sum_v = sum_v;

    for (int i=k; i<n; i++) {
        sum_v += v.at(i) - v.at(i-k);
        max_sum_v = max(max_sum_v, sum_v);
    }

    printf("%.12lf\n", max_sum_v);

    return 0;
}

