#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,d,a[10005];
    int vis[22222];
    cin>>n>>d;
    memset(vis,0,sizeof(vis));

    for(int i=0;i<n;i++) {
        cin>>a[i];
        vis[a[i]]++;
    }
    int ans=0;
    for(int i=1;i<=n-1;i++) {
        if(a[i]-d>=0 && a[i]+d<=2e4 && vis[a[i]-d] && vis[a[i]+d])
            ans+=vis[a[i]-d]*vis[a[i]+d];
    }
    cout<<ans<<endl;
}
