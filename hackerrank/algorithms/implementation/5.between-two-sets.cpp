#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[111],b[111];
int gcd2(int x, int y)
{
    return y==0?x:gcd2(y,x%y);
}
int lcm2(int x,int y) {
    return x*y/gcd2(x,y);
}

int gcd(int l,int r) {
    if(l==r)
        return b[l];
    else {
        return gcd2(b[l],gcd(l+1,r));
    }
}
int lcm(int l,int r) {
    if(l==r)
        return a[l];
    else {
        return lcm2(a[l],lcm(l+1,r));
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&b[i]);
    }
    int g=gcd(1,m),l=lcm(1,n);
    int cnt=0;
    for(int i=1;i<=g/l;i++) {
        if(g%(l*i)==0)
            cnt++;
    }
    printf("%d\n", cnt);

}
