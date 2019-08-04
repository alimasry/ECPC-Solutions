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
 
const int N = 2005;
 
ll vis[N][N], vid;
ll t, n, m, a[N], b[N], c[N], dp[N][N], p[N], s[N], pre[N][N], nxt[N][N];
 
ll solve(int i, int j) {
    if (i == n) 
        return j == m ? 0 : INF;
    ll& ret = dp[i][j];
    if (vis[i][j] == vid) return ret;
    vis[i][j] = vid;
    ret = INF;
 
    if (j < m && a[i] == b[j])
        ret = min(ret, solve(i + 1, j + 1));
 
    if (j == 0 || pre[i][j - 1] == 0)
        ret = min(ret, solve(i + 1, j) + c[i]);
    if (nxt[i][j] == 0)
        ret = min(ret, solve(i + 1, j) + c[i]);
 
    return ret;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    freopen("transform.in", "r", stdin);
 
    cin >> t;
 
    while (t--) {
        ++vid;
        cin >> n >> m;
 
        memset(pre, 0, sizeof(pre));
        memset(nxt, 0, sizeof(nxt));
 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
 
        for (int i = 0; i < m; ++i) 
            cin >> b[i];
 
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            sum += c[i];
        }
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j) 
                    pre[i][j] = pre[i][j - 1];
                if (a[i] == b[j]) 
                    ++pre[i][j];
            }
 
            for (int j = m - 1; ~j; --j) {
                nxt[i][j] = nxt[i][j + 1];
                if (a[i] == b[j])
                   ++nxt[i][j];
            }
        }
        
        memset(dp, -1, sizeof(dp));
        ll calc = solve(0, 0);
        if (calc <= 10ll * N * MOD)
            cout << calc << endl;
        else
            cout << "No" << endl;
    }
}