#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
int a[30];
char s[1005];
int dp[1005], dp2[1005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        for(int i=1;i<=n;i++) {
            cin>>s[i];
        }
        for(int i=0;i<26;i++) {
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        memset(dp2, 0x3f, sizeof(dp2));
        int len=-1;
        dp[0]=1;dp2[0]=0;
        for(int i=1;i<=n;i++) {
            int cnt[30];
            memset(cnt,0,sizeof(cnt));
            for(int j=i;j>0;j--) {
                int u=s[j] - 'a';
                cnt[u]++;
                if(cnt[u]>a[u]) { 
                    break;
                }
                dp[i]=(dp[i]+dp[j-1])%M;
                if(j!=1) {
                    len=max(len,i-j+1);
                    dp2[i]=min(dp2[i], dp2[j-1]+1);
                }
            }
        }
        cout<<dp[n]<<endl;
        cout<<len<<endl;
        cout<<dp2[n]<<endl;
    }
}
