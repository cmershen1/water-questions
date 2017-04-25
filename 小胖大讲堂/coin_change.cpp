#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main(){
    int n,m;
    int coin[1000];
    int dp[1000];
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>coin[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<n;j++) {
            if(coin[j]<=i)
                dp[i]=min(dp[i],dp[i-coin[j]]+1);
        }
    }
    if(dp[m]==INF)
        cout<<-1<<endl;
    else
        cout<<dp[m]<<endl;
}
