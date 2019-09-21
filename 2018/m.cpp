#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

ll t, n, m, x[N], q[N], r[N], y[N], d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    freopen("business.in", "r", stdin);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i) 
            cin >> x[i] >> q[i] >> r[i];

        for (int i = 0; i < m; ++i)
            cin >> y[i] >> d[i];

        multiset<pll> ends;
        ordered_set<pll> have;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && x[j] <= y[i]) {
                ends.insert({x[j] + r[j], j});
                have.insert({q[j] - x[j], j});
                ++j;
            }

            while (!ends.empty() && ends.begin()->first < y[i]) {
                int idx = ends.begin()->second;
                have.erase({q[idx] - x[idx], idx});
                ends.erase(ends.begin());
            }

            cout << (int) have.size() - have.order_of_key({d[i] - y[i], -INF}) << " \n"[i == m - 1];
        }
    }
}

