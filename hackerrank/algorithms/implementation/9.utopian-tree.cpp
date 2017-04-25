#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[61];
void pre() {
    h[0]=1;
    for(int i=1;i<=60;i++) {
        if(i&1)
            h[i]=h[i-1]*2L;
        else
            h[i]=h[i-1]+1L;
    }
}
int main(){
    pre();
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        printf("%lld\n", h[n]);
    }
}
