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
 
ll t, q;
ll tree[4 * N], lazy[4 * N];
 
void build(int l = 0, int r = N - 1, int p = 1) {
    if (l == r) {
        tree[p] = (l != 0);
    } else {
        int mid = l + ((r - l) >> 1);
 
        build(l, mid, p << 1);
        build(mid + 1, r, p << 1 | 1);
 
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
}
 
void update(int s, int e, int l = 0, int r = N - 1, int p = 1) {
    if (lazy[p]) {
        tree[p] *= -1;
        lazy[p] = 0;
 
        if (l != r) {
            lazy[p << 1] ^= 1;
            lazy[p << 1 | 1] ^= 1;
        }
    }
 
    if (s > e || s > r || e < l)
        return;
 
    if (s <= l && e >= r) {
        tree[p] *= -1;
        if (l != r) {
            lazy[p << 1] ^= 1;
            lazy[p << 1 | 1] ^= 1;
        }
        return;
    }
 
    int mid = l + ((r - l) >> 1);
 
    update(s, e, l, mid, p << 1);
    update(s, e, mid + 1, r, p << 1 | 1);
 
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
 
ll query(int s, int e, int l = 0, int r = N - 1, int p = 1) {
    if (s > e || s > r || e < l) 
        return 0;
 
    if (lazy[p]) {
        tree[p] *= -1;
        lazy[p] = 0;
 
        if (l != r) {
            lazy[p << 1] ^= 1;
            lazy[p << 1 | 1] ^= 1;
        }
    }
 
    if (s <= l && e >= r) 
        return tree[p];
 
    int mid = l + ((r - l) >> 1);
 
    ll lCalc = query(s, e, l, mid, p << 1);
    ll rCalc = query(s, e, mid + 1, r, p << 1 | 1);
 
    return lCalc + rCalc;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    freopen("reflection.in", "r", stdin);
 
    cin >> t;
 
    while (t--) {
        cin >> q;
 
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
 
        build();
 
        while (q--) {
            int x; cin >> x;
            cout << query(0, x) << endl;
            update(x + 1, N - 1);
        }
    }
}
