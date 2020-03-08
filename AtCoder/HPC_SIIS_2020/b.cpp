#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll A, B, M;
    cin >> A >> B >> M;
    vector<ll> a(A);
    vector<ll> b(B);
    for (ll i=0; i<A; i++) cin >> a[i];
    for (ll i=0; i<B; i++) cin >> b[i];
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(*min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end()));

    for (ll i=0; i<M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        pq.push(a[x-1] + b[y-1] - c);
    }

    cout << pq.top() << endl;

    return 0;
}

