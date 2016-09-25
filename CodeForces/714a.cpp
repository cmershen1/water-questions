#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll l1,l2,r1,r2,k;
    ll ans;
    scanf("%I64d %I64d %I64d %I64d %I64d",&l1,&l2,&r1,&r2,&k);
    ll l=max(l1,r1),r=min(l2,r2);
    if(l>r)
        ans=0;
    else
        ans=r-l+1;
    if(k>=l && k<=r)
        ans--;
    printf("%I64d\n", ans);
}
