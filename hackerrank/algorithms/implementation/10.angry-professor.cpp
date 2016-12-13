#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,a;
int main(){
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        while(n--) {
            scanf("%d",&a);
            if(a<=0)
                m--;
        }
        puts(m>=0?"YES":"NO");
    }
}
