#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll exgcd(ll a,ll b) {
    if(!b) {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
bool check(ll n) {
    ll r=exgcd(7,4);
    if(n%r)
        return false;
    x*=n;
    x=((x%4)+4)%4;
    y=(n-7*x)/4;
    return y>=0;
}
int main(){
    int q;ll n;
    cin>>q;
    while(q--) {
        cin>>n;
        if(check(n))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
