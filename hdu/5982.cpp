#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int main() {
    int T,n,a,b;
    ll sum;
    while(T--) {
        scanf("%d",&n);
        sum=0;
        while (n--) {
            scanf("%d %d",&a,&b);
            sum+=a*b;
        }
        printf("%I64d\n", sum);
    }
}
