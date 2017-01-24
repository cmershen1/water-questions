#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int n,t;
typedef struct  {
    int t;//time
    int s;//score
    double r;//rate
}herb;
herb h[105];
bool cmp(herb x,herb y) {
    return x.r>y.r;
}
ll ans;
void dfs(int i,ll cur,ll sc) { //决定第i个物品放不放，当前背包容量为cur，得分为sc
    if(sc>ans)
        ans=sc;
    if(sc+h[i].r*(t-cur)<ans) return;//剩下的容积就算全放i，也得不到更优解，更何况后面的性价比更低呢
    if(i<n) {
        if(h[i].t<=t-cur) //第i个物品装得下
            dfs(i+1,cur+h[i].t,sc+h[i].s);
        dfs(i+1,cur,sc);//不放i
    }
}
int main() {
    RE("in.txt");
    WR("out.txt");
    while(scanf("%d %d",&n,&t)!=EOF) {
        for(int i=0;i<n;i++) {
            scanf("%d %d",&h[i].t,&h[i].s);
            h[i].r=(double)(h[i].s)/(double)(h[i].t);
        }
        ans=0;
        sort(h,h+n,cmp);
        dfs(0,0,0);//决定第0个物品，目前背包里容量为0,得分为0
        printf("%I64d\n", ans);
    }
}
