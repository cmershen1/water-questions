#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=-1;
int a[111][111];
int n;
void dfs(int i,int j,int sum) {
    if(i==n) {
        ans=max(ans,sum);
        return;
    }
    dfs(i+1,j,sum+a[i+1][j]);
    dfs(i+1,j+1,sum+a[i+1][j+1]);
}
int main(){

    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>a[i][j];
        }
    }
    dfs(1,1,a[1][1]);
    cout<<ans<<endl;
}
