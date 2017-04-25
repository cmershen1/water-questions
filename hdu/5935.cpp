#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
ll a[100005];
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
int main() {
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%I64d",&a[i]);
        }
        ll ans=1;
        ll v1=a[n]-a[n-1],v2=1;
        for(int i=n-1;i>=1;i--) {
            ll d=a[i]-a[i-1];
            if((d*v2)%v1==0)
                ans+=d*v2/v1;
            else {
                ll t=(d*v2/v1)+1;
                ans+=t;
                v1=d;v2=t;
            }
        }
        printf("Case #%d: %I64d\n", t,ans);
    }
}
