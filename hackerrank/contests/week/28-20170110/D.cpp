#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define eps 1e-8

#define IN "D:/water-questions/temp/input/in.txt"
#define OUT "D:/water-questions/temp/input/out.txt"

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

const int M = 1e9 + 7;
const double PI = acos(-1.0);

const int MAXN = 1e5;
const int MAXM = 1e6;

int q,n,m;
int f[MAXN+5],r[MAXN+5],sum[MAXN+5];
ll ans;
int find(int x) {
    return f[x]==x?x:f[x]=find(f[x]);
}
void un(int i,int j) {
    int x=find(i),y=find(j);
    if(x!=y) {
        if(r[x]<r[y]) {
            f[x]=y;
            sum[y]+=sum[x];
        }
        else {
            f[y]=x;
            sum[x]+=sum[y];
            if(r[x]==r[y])
                r[x]++;
        }
    }
}
int main() {
    cin>>q;
    while(q--) {
        cin>>n>>m;
        for(int i=1;i<=n;i++) {
            f[i]=i;
            r[i]=1;
            sum[i]=1;
        }
        for(int i=0;i<m;i++) {
            int u,v;
            cin>>u>>v;
            if(find(u)!=find(v))
                un(u,v);
        }
        vl cp;
        for(int i=1;i<=n;i++)
            if(f[i]==i)
                cp.pb(sum[i]);
        sort(cp.begin(),cp.end());

        ll ans=0;
        ll edge=0;
        for(int i=cp.size()-1;i>=0;i--) {
            edge+=(cp[i]-1);
            ll temp=0;
            for(int j=1;j<cp[i];j++)
                temp+=(j*(j+1ll));

            ans+=((m-edge)*cp[i]*(cp[i]-1)+temp);
        }
        cout<<ans<<endl;
    }
}

