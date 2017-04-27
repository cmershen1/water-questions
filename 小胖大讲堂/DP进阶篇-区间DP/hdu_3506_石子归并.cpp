#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
int dp[2001][2001];
int a[2001];
int sum[2001];
int k[2001][2001];
int n;
void pre() {
    for(int i=0;i<n-1;i++) {
        a[i+n]=a[i];
    }
    sum[0]=a[0];
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<2*n-1;i++) {
        sum[i]=sum[i-1]+a[i];
    }
}

int main(){
    while(cin>>n) {
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        pre();
        for(int l=1;l<=2*n-1;l++) {
            for(int i=0;i<2*n-l;i++) {
                int j=i+l-1;
                if(i==j) {
                    dp[i][j]=0;
                    k[i][j]=i;
                } else {
                    for(int s=k[i][j-1];s<=k[i+1][j];s++) {
                        int temp=dp[i][s]+dp[s+1][j]+sum[j]-sum[i-1];
                        if(temp<dp[i][j]) {
                            dp[i][j]=temp;
                            k[i][j]=s;
                        }
                    }
                }
            }
        }
        int ans=INF;
        for(int i=0;i<n;i++) {
            ans=min(ans,dp[i][i+n-1]);
        }
        cout<<ans<<endl;
    }
}
