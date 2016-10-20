#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    ll a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%I64d %I64d",&a,&b);
        printf("Case: #%d\n", i);
        if(a==b)
            printf("1\n%I64d %I64d\n", a,b);
        else {
            printf("2\n%I64d %I64d\n%I64d %I64d\n", a,b,b,a);
        }
    }
}
