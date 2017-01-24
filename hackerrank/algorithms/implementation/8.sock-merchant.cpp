#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,ans=0;
int m[111];
int main(){
    memset(m,0,sizeof(m));
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&c);
        m[c]++;
        if(!(m[c]&1))
            ans++;
    }
    printf("%d\n", ans);
}
