#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
const double PI = acos(-1.0);
typedef long long ll;
int T;
double d;
double f(double a) {
    return 2*(sin(a)-a*cos(a)-sin(a)*sin(a)*sin(a)/3)/(PI*(1-cos(a)));

}
double getalpha() {
    double l=0,r=PI;
    while(l-r<1e-11) {
        double mid=(l+r)/2;
        if(fabs(f(mid)-d)<1e-11)//这里写成1e-9就会错
            return mid;
        else if(f(mid)>d)
            r=mid;
        else
            l=mid;
    }
}
double solve() {
    if(fabs(d)<1e-11)
        return 0;
    if(fabs(d-1.0)<1e-11)
        return PI*sqrt(2.0);
    else if((d-1e-11)>1.0)  //d>1
        return PI*sqrt((2-d)*(2-d)+1.0);
    else { //d<1
        double a=getalpha();
        double s=(a-sin(2*a)/2)*sqrt(4+(1-cos(a))*(1-cos(a)))/((1-cos(a)));
        return s;
    }

}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%lf",&d);
        printf("%.5f\n", solve());
    }
}
