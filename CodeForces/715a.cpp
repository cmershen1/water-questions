#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a;
int main() {
    scanf("%I64d",&n);
    for(ll i=1;i<=n;i++) {
        if(i==1)
            a=2;
        else
            a=i*(i+1)*(i+1)-i+1;
        printf("%I64d\n", a);
    }
}
