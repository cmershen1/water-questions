#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N],b[N];
int main()
{
    int tcase,t=1;
    scanf("%d",&tcase);
    while(tcase--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        if(m>n) {
            printf("Case #%d: %d\n",t++,0);
            continue;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[1]) continue;
            int idx = 1;
            for(int j=i;j<=n;j+=k){
                if(a[j]==b[idx]){
                    idx++;
                }
                else break;
                if(idx==m+1){
                    ans++;break;
                }
            }
        }
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}
