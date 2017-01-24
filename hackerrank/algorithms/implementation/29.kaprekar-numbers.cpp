#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getd(ll a) {
    return a>=0 && a<=9?1:1+getd(a/10);
}
bool judge(ll x) {
    ll a=x*x;
    int d=getd(x);
    ll l=a/(ll)(pow(10,d));
    ll r=a%(ll)(pow(10,d));
    return l+r==x;
}
int main(){
    ll p,q;
    cin>>p>>q;
    vector<ll> ans;
    for(ll i=p;i<=q;i++) {
        if(judge(i))
            ans.push_back(i);
    }
    if(ans.size()==0) {
        cout<<"INVALID RANGE"<<endl;
        return 0;
    }
    for(int i=0;i<ans.size()-1;i++)
        cout<<ans[i]<<" ";
    cout<<ans.back()<<endl;
}
