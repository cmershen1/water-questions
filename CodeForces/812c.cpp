#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll s;
ll a[100005];
ll b[100005];

ll getsum(int k) {
    for (int i=1; i<=n; i++) {
        b[i] = a[i] + (ll)i*k;
    }
    sort(b+1, b+1+n);
    ll sum=0;
    for (ll i=1; i<=k; i++) {
        sum+=b[i];
    }
    return sum;
}

int main() {
    while (cin >> n >> s) {
        for (ll i=1; i<=n; i++) {
            cin >> a[i];
        }
        ll l=0, r=n;
        while (l<r) {
            int mid=(l+r+1)/2;
            if (getsum(mid) <= s)
                l = mid;
            else
                r = mid-1;
        }
        cout << l << " " << getsum(l) << endl;
    }
}
