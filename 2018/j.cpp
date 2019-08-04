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
 
ll t, n, dist[N], dp[N][2];
bool ans[N], vis[N];
 
ll solve(int i, int pre) {
    i %= n;
 
    if (vis[i]) return -INF;
    if (i == 0) return 1;
 
    ll& ret = dp[i][pre];
 
    if (~ret) return ret;
    vis[i] = true;
 
    bool p = i == ((n + (i << 1)) >> 1) % n;
    ret = max(solve(i << 1, p), solve(i << 1 | 1, p)) + 1;
 
    vis[i] = false;
    return ret;
}
 
void build(int i, int pre, bool cur = 1) {
    i %= n;
 
    cout << cur;
 
    if (i == 0) return;
 
    ll& ret = dp[i][pre];
 
    bool p = i == ((n + (i << 1)) >> 1) % n;
 
    if (ret == solve(i << 1, p) + 1) 
        build(i << 1, p, 0);
    else
        build(i << 1 | 1, p, 1);
}
 
void clear() {
    memset(dist, -1, n * sizeof(ll));
    memset(dp, -1, sizeof(dp));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    freopen("unique.in", "r", stdin);
 
    cin >> t;
    
    while (t--) {
        cin >> n;
        clear();
        solve(1, 0);
        build(1, 0);
        cout << endl;
    }
}