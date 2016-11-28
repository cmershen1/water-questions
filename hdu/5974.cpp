#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll a,b;
int T;
int main() {
    RE("in.txt");
    WR("out.txt");
    while(~scanf("%I64d %I64d",&a,&b)) {
        ll c=gcd(a,b);
        ll dt=a*a-4*b*c;
        if(dt<0) {
            cout<<"No Solution"<<endl;
            continue;
        }
        else {
            ll sq=sqrt(dt);
            if(sq*sq!=dt) {
                cout<<"No Solution"<<endl;
                continue;
            }
            else if((a+sq)%(2*c)){
                cout<<"No Solution"<<endl;
                continue;
            }
            else {
                ll x1=(a-sq)/2;
                ll x2=(a+sq)/2;
                cout<<x1<<' '<<x2<<endl;
            }
        }

    }
}
