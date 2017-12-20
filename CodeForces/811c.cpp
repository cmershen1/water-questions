#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int fr[5005],ls[5005],prexor[5005],dp[5005],vis[5005];

void init() {
    //pre-calc fr[x],ls[x]
    memset(fr, 0, sizeof(fr));
    memset(ls, 0, sizeof(ls));

    for(int i=1; i<=n; i++) {
        if (fr[a[i]] == 0)
            fr[a[i]] = i;
    }
    for(int i=n; i>=1; i--) {
        if (ls[a[i]] == 0)
            ls[a[i]] = i;
    }
    //pre-calc xor(1...n)
    // prexor[0]=0;
    // for(int i=1; i<=n; i++) {
    //     prexor[i]=a[i]^prexor[i-1];
    // }
}
int main() {
    while (cin>>n) {
        for (int i=1; i<=n; i++) {
            cin>>a[i];
        }
        init();
        dp[0]=0;
        for (int i=1; i<=n; i++) {
            dp[i] = dp[i-1];
            int cur = 0, left = i, right = 1;
            memset(vis, 0, sizeof(vis));
            for (int j=i; j>=1; j--) {
                if (!vis[a[j]]) {
                    left = min(left, fr[a[j]]);//取序列中每个元素的fr最小值
                    right = max(right, ls[a[j]]);//取序列中每个元素的ls最大值
                    cur ^= a[j];//维护xor(j...i)
                    vis[a[j]] = 1;
                }
                if (left == j && right == i) //[j...i]可以合并
                    dp[i] = max(dp[i], dp[j-1] + cur);
            }
        }
        cout<<dp[n]<<endl;
    }
}
