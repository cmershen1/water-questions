#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
int T,x,k;
ll f[10][100005],f1[10][100005],f2[10][100005];
void pre() {
    for(int k=0;k<=9;k++) {
        for(int i=0;i<1e5;i++) {
            if(i<10)
                f[k][i]=pow(i,k);
            else
                f[k][i]=f[k][i/10]+pow(i%10,k);
            f1[k][i]=f[k][i]-i*1e5;
            f2[k][i]=f[k][i]-i;
        }
    }
    for(int k=0;k<=9;k++) {
    //    sort(f1[k],f1[k]+100000);
        sort(f2[k],f2[k]+100000);
    }
}
ll solve() {
    ll ans=0;
    for(int i=0;i<1e5;i++) {
        ll target=x-f1[k][i];
        int l=lower_bound(f2[k],f2[k]+100000,target)-f2[k];
        int r=upper_bound(f2[k],f2[k]+100000,target)-f2[k];
        ans+=r-l;
    }
    if(x==0)
        ans--;
    return ans;
}
int main() {
    RE("in.txt");
    WR("out.txt");
    clock_t start=clock();
    pre();

    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d %d",&x,&k);
        ll ans=solve();
        printf("Case #%d: %I64d\n", t,ans);
    }
    clock_t end=clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
