#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int d[100005],a[100005];
bool check(int u) {
    int exam[100005],vis[100005];
    memset(exam,0,sizeof(exam));
    memset(vis,0,sizeof(vis));
    for(int i=u;i>=1;i--) {
        if(d[i] && !vis[d[i]]) {
            exam[i]=d[i];//第i天考d[i]
            vis[d[i]]=true;
        }
    }
    int pre=0;
    for(int i=1;i<=u;i++) {
        if(exam[i]) {
            pre-=a[exam[i]];;
            if(pre<0)
                return false;
        } else {
            pre++;
        }
    }
    for(int i=1;i<=m;i++) {
        if(!vis[i])
            return false;
    }
    return (pre>=0);
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>d[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>a[i];
    }
    int l=1,r=n;
    while(l<r) {
        int mid=(l+r)/2;
        if(check(mid)) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    if(check(l))
        cout<<l<<endl;
    else
        cout<<-1<<endl;
}
