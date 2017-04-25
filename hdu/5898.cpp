#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll l,r;
ll dp[20][20][20];
int bit[20];
ll dfs(int pos,int j,int k,bool lead,bool limit) {
    //从pos位开始，上一位是j，连续的奇数或者偶数有k，有没有前导0，第pos位是否有上界（即如果求1~8000，最高位只能取到8）
    //返回这一条件下，符合答案的数
    if(pos==-1)
        return (j+k)%2;
    if(!limit && !lead && dp[pos][j][k]!=-1)
        return dp[pos][j][k];

    int up = limit?bit[pos]:9; //范围到up
    ll ans=0;

    if(lead) {
        for(int i=0;i<=up;i++) {
            ans+=dfs(pos-1,i,1,i==0,limit && i==bit[pos]);
        }
    }
    else if((j+k)%2==1) {
        for(int i=0;i<=up;i++) {
            if((i+j)%2==0)
                ans+=dfs(pos-1,i,k+1,false,limit && i==bit[pos]);
            else
                ans+=dfs(pos-1,i,1,false,limit && i==bit[pos]);
        }
    }
    else {
        for(int i=0;i<=up;i++) {
            if((i+j)%2==0)
                ans+=dfs(pos-1,i,k+1,false,limit && i==bit[pos]);
        }
    }

    if(!limit && !lead)
        dp[pos][j][k] = ans;
    return ans;
}

ll solve(ll x) { //计算[1,x]内有少符合条件的数
    int pos=0;
    bit[0]=0;
    while(x) {//把数字x按位拆开放进数组里面,从最高位在pos-1，最低位是0
        bit[pos++]=x%10;
        x/=10;
    }
    // for(int i=0;i<pos;i++)
    //     printf("bit[%d] = %d\n", i,bit[i]);
    return dfs(pos-1,0,1,true,true);
}
int main() {
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=t;i++) {
        scanf("%I64d %I64d",&l,&r);
        printf("Case #%d: %I64d\n", i,solve(r)-solve(l-1));
    }
}
