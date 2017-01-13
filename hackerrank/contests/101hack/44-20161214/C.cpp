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

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 6;

int main() {
    //RE("in.txt");WR("out.txt");
    ll f[MAXN];
    f[1]=1;
    for(int i=2;i<=100000;i++) {
        f[i]=(f[i-1]*i)%M;
    }
    ll n;
    cin>>n;
    ll x=n*(1e9+8)/2;
    x=x%M;
    cout<<x*f[n]%M<<endl;
}