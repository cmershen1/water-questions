#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const double PI = acos(-1.0);
const int M = 1e9+7;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
int T;
ll a;
int main() {

    scanf("%d",&T);
    int cnt=0;
    for(int t=1;t<=T;t++) {
        scanf("%lld",&a);
        while(a) {
            if(a%256==97)
                cnt++;
            a/=256;
        }
    }
    printf("%d\n",cnt);
}
