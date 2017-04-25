#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
int dp[5005][5005];
int main(){
    memset(dp,0,sizeof(dp));
    cin>>a>>b;
    for(int i=0;i<=a.length();i++) {
        for(int j=0;j<=b.length();j++) {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[a.length()][b.length()]<<endl;

}
