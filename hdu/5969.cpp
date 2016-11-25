#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
ll l,r;
int T;
int get(ll r) {
    return (r<2)?1:get(r/2)+1;
}
int main(){
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    while(T--)  {
        scanf("%I64d %I64d",&l,&r);
        ll ans=0;
        int i=get(r)-1;

        while(i>=0) {
            if((r&(1LL<<i))==(l&(1LL<<i)))
                ans+=r&(1LL<<i);
            else
                break;
            i--;
        }
        if(i!=-1)
            ans+=(1LL<<(1+i))-1;
        cout<<ans<<endl;
    }

}
