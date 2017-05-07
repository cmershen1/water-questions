#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[111][111];
int ans[111];
int main(){
    string a,b;
    while(cin>>a>>b) {
        int n=a.length();
        memset(dp,0,sizeof(dp));
        for(int l=1;l<=n;l++) {
            for(int i=0;i<=n-l;i++) {
                int j=i+l-1;
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++) {
                    if(b[i]==b[k])
                        dp[i][j]=min(dp[i][j], dp[i+1][k]+dp[k+1][j]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            ans[i]=dp[0][i];
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                ans[i]=min(ans[i],dp[j+1][i]+ans[j]);
            }
            if(a[i]==b[i])
                ans[i]=min(ans[i],ans[i-1]);
        }
        cout<<ans[n-1]<<endl;
    }
}
