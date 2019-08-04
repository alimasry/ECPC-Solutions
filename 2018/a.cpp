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
 
ll t, x, y, m, k;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    freopen("zeros.in", "r", stdin);
 
    cin >> t;
 
    while (t--) {
        cin >> x >> y >> m >> k;
 
        if (x + y == 1) {
            cout << (k <= 1) << endl;
            continue;
        }
 
        int l = (x + y) >> 1;
        int r = x + y - l;
 
        --l; // because the first bit is always 1
 
        vector<vector<ll>> rhs(x + 1);
        for (int mask = 0; mask < (1 << l); ++mask) {
            ll sum = (((1ll << l) % m + mask) << r) % m;
            int ones = 1 + __builtin_popcount(mask), zeros = l - ones + 1;
            if (ones <= x && zeros <= y) {
                rhs[ones].push_back(sum);
            }
        }
 
        for (auto &v : rhs)
            sort(v.begin(), v.end());
 
        ll ans = 0;
        for (int mask = 0; mask < (1 << r); ++mask) {
            ll sum = mask % m;
            int ones = __builtin_popcount(mask), zeros = r - ones;
            if (ones <= x && zeros <= y) {
                int ind = x - ones;
 
                int en = upper_bound(rhs[ind].begin(), rhs[ind].end(), m - 1 - sum) - rhs[ind].begin();
                int st = lower_bound(rhs[ind].begin(), rhs[ind].end(), k - sum) - rhs[ind].begin();
                ans += en - st;
 
                int extra = lower_bound(rhs[ind].begin(), rhs[ind].end(), m - sum + k) - rhs[ind].begin();
                ans += (int) rhs[ind].size() - extra;
            }
        }
 
        cout << ans << endl;
    }
}