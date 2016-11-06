#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,u,v;
short a[100005];
int deg[100005];
vector<int> g[100005];
int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++) {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;deg[v]++;
        }
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++) {
            if(deg[i]&1)
                cnt++;
            int temp=(deg[i]+1)/2;
            if(temp & 1)
                sum^=a[i];
        }
        if(cnt==0) { //Eular Curcuit
            int ans=0;
            for(int i=1;i<=n;i++)
                ans=max(ans,sum^a[i]);
            printf("%d\n", ans);
        }
        else if(cnt==2)  //Eular Path
            printf("%d\n", sum);
        else
            printf("Impossible\n");
    }
}
