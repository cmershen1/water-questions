#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
int T,ans;
ll state;
int a[12];
int x[36]={1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,6,6,6,7,7,8};
int y[36]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,1,2,3,4,5,6,1,2,3,4,5,1,2,3,4,1,2,3,1,2,1};
int z[36]={2,3,4,5,6,7,8,9,3,4,5,6,7,8,9,4,5,6,7,8,9,5,6,7,8,9,6,7,8,9,7,8,9,8,9,9};
bool special() {
    for(int i=1;i<=9;i++) {
        if(a[i]+i<17)
            return false;
    }
    return true;
}
void dfs(int u) { //已经搜到u个等式,当前状态是state（36位二进制串，初始化全0)
    if(u>ans) ans=u;
    for(int i=0;i<36;i++) {
        if((state&(1<<i))==0) {//第i个等式还没放过
            if(x[i]!=y[i] && a[x[i]]>=1 &&a[y[i]]>=1 && a[z[i]]>=1) {
                a[x[i]]--;a[y[i]]--;a[z[i]]--;
                state+=1<<i;
                dfs(u+1);
                state-=1<<i;
                a[x[i]]++;a[y[i]]++;a[z[i]]++;
            }
            else if(x[i]==y[i] && a[x[i]]>=2 && a[z[i]]>=1) {
                a[x[i]]-=2;a[z[i]]--;
                state+=1<<i;
                dfs(u+1);
                state-=1<<i;
                a[x[i]]+=2;a[z[i]]++;
            }
        }
    }
}
int main() {
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        for(int i=1;i<=9;i++) {
            scanf("%d",&a[i]);
        }
        if(special()) {
            printf("36\n");
        }
        else {
            ans=0;state=0;
            dfs(0);
            printf("Case #%d: %d\n", t,ans);
        }
    }
}
