#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,m;
    int a[105];
    int sum[105];

    cin>>n>>m;
    sum[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    while(m--) {
        int i,j;
        cin>>i>>j;
        if(sum[j]-sum[i-1]>0)
            ans+=sum[j]-sum[i-1];
    }
    cout<<ans<<endl;
}
