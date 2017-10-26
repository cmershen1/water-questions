#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_len(ll x) {
    return (x <= 1) ? x : 2 * get_len(x / 2) + 1;
}
ll dfs(ll start, ll end, ll l, ll r, ll cur) {
    if (start > end) return 0;
    if (l > r) return 0;
    ll mid = (start + end) / 2;
    if (r < mid)
        return dfs(start, mid-1, l, r, cur/2);
    else if (l > mid)
        return dfs(mid+1, end, l, r, cur/2);
    else
        return dfs(start, mid-1, l, mid-1, cur/2) + cur%2 + dfs(mid+1, end, mid+1, r, cur/2);
}
int main() {
    ll n,l,r;
    cin>>n>>l>>r;
    ll f = get_len(n);
    ll ans = dfs(1, f, l, r, n);
    cout << ans << endl;
}
