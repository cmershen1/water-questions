#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll x,y,l,r;
set<ll> s;

int main() {
    while (cin >> x >> y >> l >> r) {
        s.clear();
        ll p=1;
        ll d1 = r;
        while(p < r) {

            ll q=1;
            ll d2 = r;
            while(q < r) {

                ll a = p+q;
                if (l <= a && a <= r) { // a in [l,r]
                    s.insert(a);
                }
                d2 /= y;
                if (d2 == 0)
                    break;
                q*=y;

            }
            d1 /= x;
            if (d1 == 0)
                break;
            p*=x;
        }

        ll ans = 0;
        if (s.size() == 0)
            ans = r-l+1;
        else {
            vector<ll> v;
            for (auto i : s) {
                v.push_back(i);
            }

            for (int i=0; i<v.size()-1; i++) {
                ans = max(ans, v[i+1]-v[i]-1);
            }
            ans = max(ans, v.front()-l);
            ans = max(ans, r-v.back());
        }
        cout << ans << endl;
    }
}
