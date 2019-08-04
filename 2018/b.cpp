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
 
const int N = 1e5 + 5;
 
ll t, n, a[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    freopen("task.in", "r", stdin);
 
    cin >> t;
 
    while (t--) {
        cin >> n;
 
        ll ans = n + 1;
 
        set<ll> have;
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
 
        sort(a, a + n);
 
        ll dup = 0;
        for (int i = 0; i < n; ++i) {
            if (!have.insert(a[i]).second)
                ++dup;
            ans = min(ans, *have.rbegin() - (ll) have.size() + n - i - 1 + dup);
        }
 
        cout << ans << endl;
    }
}