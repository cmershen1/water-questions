#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,x,a;
    cin>>n>>x;
    while(n--) {
        cin>>a;
        m[a]++;
    }
    ll ans=0;
    for(auto i : m) {
        ll k=x^(i.first);
        if(x==0) {
            ans+=m[k]*(m[k]-1);
        } else {
        ans+=m[k]*i.second;
        }
    }
    cout<<ans/2<<endl;
}
