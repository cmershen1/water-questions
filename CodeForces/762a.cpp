#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    while(cin>>n>>k) {
        int cnt=0;
        vector<ll> s;
        for(ll a=1;a*a<=n;a++) {
            if(n%a==0) {
                s.push_back(a);
                if(a*a!=n)
                    s.push_back(n/a);
            }
        }
        sort(s.begin(), s.end());
        if(k>s.size())
            cout<<-1<<endl;
        else
            cout<<s[k-1]<<endl;

    }
}
