#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const double PI = acos(-1.0);
const int M = 1e9+7;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
int n,d,a;
int main() {
    //RE("in.txt");WR("out.txt");
    while(~scanf("%d %d",&n,&d)) {
        double ans=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a);
            ans+=d*d*sin(a*1.0/180*PI)/2;
        }
        printf("%.3f\n",ans);
    }
}
