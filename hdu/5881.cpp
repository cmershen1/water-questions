#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r;
int main() {
    while(scanf("%I64d %I64d",&l,&r)!=EOF) {
        ll ans;
        if(r<=1)
            ans=0;
        else if(r<=2)
            ans=1;
        else if(r-l<=1)
            ans=2;
        else {
            if(l<=1) l=1;
            ans=(r-l)/2+1;
        }
        printf("%I64d\n", ans);
    }
}
