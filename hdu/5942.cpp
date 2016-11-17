#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T;ll n;
const int M = 1e9+7;
const int maxn = 1e6;

ll phi[maxn+5];
ll euler()
{
    int i,j;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(i=2;i<maxn;++i)//先打表出每个数的互质数个数
    {
        if(!phi[i])
        {
            for(j=i;j<maxn;j+=i)
            {
                if(!phi[j])
                    phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int fac[1000005][20];
bool vis[maxn+5];
void Get_fac(int m)
{
    int m2=m;
    vis[m2]=true;
    int i,x=0;
    for(i=2;i*i<=m;i++)
        if(m%i==0){
            fac[m2][++x]=i;
            while(m%i==0)   m/=i;
        }
    if(m!=1) {
        fac[m2][++x]=m;

    }
    fac[m2][0]=x;
}

int sum[1<<11],q;
ll Sum(int m,ll n)
{
    int i,j;
    if(!vis[m])
        Get_fac(m);
    sum[0]=1;
    sum[1]=1;
    for(i=1;i<=fac[m][0];i++)
    {
        int k=sum[0];
        for(j=1;j<=sum[0];j++)
        {
            sum[++k]=fac[m][i]*sum[j]*-1;
        }
        sum[0]=k;
    }

    ll ret=n;
    for(i=2;i<=sum[0];i++)   ret+=n/sum[i];
    return ret;
}

ll solve() {
    ll ans=0;
    for(ll p=1;p*p<n;p++) {
        ans=(ans+Sum(p,n/p)-phi[p])%M;
    }
    return (ans*2+1)%M;
}
int main() {
    euler();
    memset(vis,0,sizeof(vis));
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n", t,solve());
    }
}
