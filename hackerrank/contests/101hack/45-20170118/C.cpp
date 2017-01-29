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

const int MAXN = 1e3;
const int MAXM = 1e6;
ll a[MAXN+5];
int n;
ll pre[MAXN+5],suf[MAXN+5];
ll gcd(ll a, ll b) {
    return b==0?a:gcd(b,a%b);
}
int main() {
    //RE(IN);WR(OUT);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    ms(pre,0);ms(suf,0);
    //预处理前缀gcd和后缀gcd
    pre[1]=a[1];
    for(int i=2;i<=n;i++)
        pre[i]=gcd(a[i],pre[i-1]);
    suf[n]=a[n];
    for(int i=n-1;i>=1;i--)
        suf[i]=gcd(a[i],suf[i+1]);
    
    for(int i=1;i<=n;i++) {
        ll g;
        if(i==1)
            g=suf[2];
        else if(i==n)
            g=pre[n-1];
        else
            g=gcd(pre[i-1],suf[i+1]);
        
        if(gcd(g,a[i])==1) {
            cout<<g<<endl;
            //break;
        }
            
    }
}