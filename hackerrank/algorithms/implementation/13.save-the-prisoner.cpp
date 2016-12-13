#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,s;
int main(){
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&s);
        int ans=(s+m-1)%n;
        if(ans==0) ans=n;
        printf("%d\n", ans);
    }

}
