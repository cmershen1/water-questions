#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T,n;
char s[20];
ll myatol(int start,int end) {//[start,end)
    ll ans=0;
    for(int i=start;i<end;i++) {
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}
ll add1(int i) { //[0,i)
    ll x1=s[0]-'0',x2=myatol(1,i);
    ll y1=myatol(0,i-1),y2=s[i-1]-'0';
    return max(x1+x2,y1+y2);
}
ll add2(int i) { //[i,n)
    return (s[i]-'0')*(s[i+1]-'0')/myatol(i+2,n);
}
int main() {
//    RE("in.txt");
//    WR("out.txt");
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%s",s);
        n=strlen(s);
        ll ans=-1e18;
        for(int i=2;i<n-2;i++) {
            ll left=add1(i);//[0,i)的子串添加+号
            ll right=add2(i);//[i,n)子串添加* /号
            ans=max(ans,left-right);
        }
        printf("Case #%d: %I64d\n",t, ans);
    }
}
