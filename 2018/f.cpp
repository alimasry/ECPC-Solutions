#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define endl "\n"
 
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);
 
ll t, n, m, x, y;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    freopen("mosalah.in", "r", stdin);
 
    cin >> t;
 
    while (t--) {
        cin >> n >> m >> x >> y;
        ll ans = max(n * (x + y) - m, 0ll);
        if (y == 0 && n * (x + y) > m)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}