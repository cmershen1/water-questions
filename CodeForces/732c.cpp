#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=LONG_LONG_MAX;
    ll m=max(a,max(b,c));
    ans=min(ans,m-a+m-b+m-c);

    m=max(a,max(b,c+1));
    ans=min(ans,m-a+m-b+m-1-c);

    m=max(a,max(b+1,c+1));
    ans=min(ans,m-a+m-1-b+m-1-c);

    m=max(a+1,max(b,c+1));
    ans=min(ans,m-a-1+m-b+m-1-c);

    m=max(a+1,max(b,c));
    ans=min(ans,m-a-1+m-b+m-c);

    m=max(a,max(b+1,c));
    ans=min(ans,m-a+m-b-1+m-c);

    m=max(a+1,max(b+1,c));
    ans=min(ans,m-a-1+m-b-1+m-c);

    cout<<ans<<endl;
}
