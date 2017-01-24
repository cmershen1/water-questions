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

const int MAXN = 1e5;
const int MAXM = 1e6;

ll q,x;
int main() {
    cin>>q;
    while(q--) {
        cin>>x;
        ll ans=0;
        for(int i=0;i<35;i++) {
            ll t=(1ll<<i);
            if(t>=x)
                break;
            if(!(t&x))
                ans+=(1ll<<i);
        }
        cout<<ans<<endl;
    }
}