#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[100];
    int dp[100];

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        dp[i]=1;
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[j]<a[i])
                dp[i]=max(dp[i], dp[j]+1);
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        ans=max(ans, dp[i]);
    }
    cout<<ans<<endl;
}
