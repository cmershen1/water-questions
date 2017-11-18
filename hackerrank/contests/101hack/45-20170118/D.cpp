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

int n,q,a,b;
int c[MAXN+5];

ll tr[MAXN+5];
int egcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int ans = egcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return ans;
}
int cal(int a, int m = M) {
  int x, y;
  int gcd = egcd(a, m, x, y);
  if (1 % gcd != 0)
    return -1;
  x *= 1 / gcd;
  m = abs(m);
  int ans = x % m;
  if (ans <= 0)
    ans += m;
  return ans;
}

inline int lowbit(int x) {
    return x&-x;
}
void add(int i,ll j) {
    while(i<=n) {
        tr[i]=(tr[i]+j)%M;
        i+=lowbit(i);
    }
}
ll sum(int i) {
    ll ans=0;
    while(i>0) {
        ans=(ans+tr[i])%M;
        i-=lowbit(i);
    }
    return ans;
}
ll x0[MAXN+5];
void pre() {
    ms(tr,0);
    x0[0]=1;
    if(a!=0) {
        for(int i=1;i<n;i++) {
            x0[i]=(x0[i-1]*b)%M;
            x0[i]=(x0[i]*cal(a))%M;
            x0[i]=M-x0[i];//注意把结果一定要限定在[0,M)范围内，负数要修正，这里相当于乘以-1！！
        }
    }
}
int main() {
    cin>>n>>a>>b>>q;
    pre();
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        add(i,(c[i]*x0[i-1])%M);
    }
    while(q--) {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1) {
            ll delta=((z-c[++y]+M)*x0[y-1])%M;//同样的，这里直接写z-c[++y]会wa，但是因为2M*M大约是2e18，也不会爆ll（最大到9e18），这里不用加%M。
            add(y,delta);
            c[y]=z;
        }
        else if(x==2) {
            if(a==0)
                cout<<"Yes"<<endl;
            else if(b==0) {
                if(c[y+1]==0)
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }
            else {
                ll px=sum(z+1)-sum(y);
                if(px==0)
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }
        }
    }
}
