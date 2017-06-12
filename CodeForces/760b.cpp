#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll f(ll x) {
    ll a,b;
    a = (x>=k) ? (2*x-k+1)*k/2 : x*(x+1)/2+k-x;
    b = (x-n+k>=1) ? (2*x-1-n+k)*(n-k)/2 : x*(x-1)/2+n-k-x+1;
    return a+b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m >> k) {
        ll l=1,r=m;
        while(l<=r) {
            ll mid=l+(r-l)/2;
            if(f(mid)<=m && m<f(mid+1)) {
                cout<<mid<<endl;
                break;
            }
            else if(f(mid)>m)
                r=mid-1;
            else
                l=mid+1;
        }
    }
}
