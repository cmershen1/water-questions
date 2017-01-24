#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define eps 1e-8

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

const int M = 1e9 + 7;
const double PI = acos(-1.0);

const int MAXN = 2e5;
const int MAXM = 1e6;

int n;
char s[MAXN+5];
ll dp[MAXN+5][10];

void dfs(int pos,int mod) {
    if(pos==n) {
        dp[pos][mod]=(mod==0);
        return;
    }
    else if(dp[pos][mod]!=-1)
        return;
    int nextmod=(mod*10+(s[pos]-'0'))%8;
    dfs(pos+1,mod);
    dfs(pos+1,nextmod);

    dp[pos][mod]=(dp[pos+1][mod]+dp[pos+1][nextmod])%M;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    ms(dp,-1);
    dfs(0,0);
    cout<<dp[0][0]-1<<endl;
}
