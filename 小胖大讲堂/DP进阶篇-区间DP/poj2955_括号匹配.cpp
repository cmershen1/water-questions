#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int dp[500][500];

void dfs(int i,int j) {
    if(i>=j) {
        dp[i][j]=0;
        return ;
    }
    if((s[i]=='(' && s[j]==')')||(s[i]=='[' && s[j]==']')) {
        if(dp[i+1][j-1]==-1)
            dfs(i+1,j-1);
        dp[i][j] = dp[i+1][j-1]+2;
    }
    for(int k=i;k<=j;k++) {
        if(dp[i][k]==-1)
            dfs(i,k);
        if(dp[k+1][j]==-1)
            dfs(k+1,j);
        dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
    }
}
int main(){
    while(cin>>s) {
        if(s=="end")
            return 0;
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        dfs(0,n-1);
        cout<<dp[0][n-1]<<endl;
    }
}
