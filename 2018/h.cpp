#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define endl '\n'
 
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);
 
const int N = 1e5 + 5;
 
set<pll> have;
vector<pll> G[N];
ll t, n, u, m, l, k, vis[N], vid;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("path.in", "r", stdin);

    cin >> t;

    while (t--) {
        ++vid;

        cin >> n >> m >> u >> l >> k;

        for (int i = 0; i < m; ++i) {
            int x, y, w; cin >> x >> y >> w;
            G[x].emplace_back(y, w);
            G[y].emplace_back(x, w);
        }

        ll ans = 0;

        queue<pll> q;
        q.push({u, k});
        vis[u] = vid;
        while (!q.empty()) {
            ll r = q.front().first;
            int w = q.front().second;
            q.pop();
            if (w == 0) 
                continue;
            for (auto& to : G[r]) {
                if (have.insert({min(r, to.first), max(r, to.first)}).second) {
                    vis[to.first] = vid;
                    ans = max(ans, to.second);
                    q.push({to.first, w - 1});
                }
            }
        }

        cout << ans << endl;

        for (int i = 1; i <= n; ++i) 
            G[i].clear();
        have.clear();
    }
}