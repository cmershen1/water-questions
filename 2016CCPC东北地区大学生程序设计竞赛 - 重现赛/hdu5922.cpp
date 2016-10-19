#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int T;ll n;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n", i,n*(n+1)/2-1);
    }
}
