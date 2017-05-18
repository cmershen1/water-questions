#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)

typedef long long ll;
int w[1005],b[1005];
int dp[100005];
int f[1005],sumw[1005],sumb[1005];
int find(int x) {
    return x==f[x]?x:f[x]=find(f[x]);
}
void Union(int x,int y) {
    x=find(x);
    y=find(y);
    if(x!=y) {
        f[x]=y;
        sumw[y]+=sumw[x];
        sumb[y]+=sumb[x];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++) {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++) {
        f[i]=i;
        sumw[i]=w[i];
        sumb[i]=b[i];
    }
    while(m--) {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    vector<int> group[1005];
    for(int i=1;i<=n;i++) {
        group[find(i)].push_back(i);
    }
    for(int k=1;k<=n;k++) {
        if(k==find(k)) {
            for(int j=x;j>=0;j--) {
                for(int i : group[k]) {
                    if(j>=w[i])
                        dp[j]=max(dp[j], dp[j-w[i]]+b[i]);
                }
                if(j>=sumw[k])
                    dp[j]=max(dp[j], dp[j-sumw[k]]+sumb[k]);
            }

        }
    }

    cout<<dp[x]<<endl;

}
