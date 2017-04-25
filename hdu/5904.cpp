#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m;
int a[100005],b[100005];
int dp1[1000005],dp2[1000005];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        int m1=-1,m2=-1;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            m1=max(m1,a[i]);
        }
        dp1[a[0]]=1;
        for(int i=1;i<n;i++)
            dp1[a[i]]=dp1[a[i]-1]+1;
        for(int i=0;i<m;i++) {
            scanf("%d",&b[i]);
            m2=max(m2,b[i]);
        }
        dp2[b[0]]=1;
        for(int i=1;i<m;i++)
            dp2[b[i]]=dp2[b[i]-1]+1;
        int ans=0,x=min(m1,m2);
        for(int i=0;i<=x;i++)
            ans=max(ans,min(dp1[i],dp2[i]));
        for(int i=0;i<n;i++)
            dp1[a[i]]=0;
        for(int i=0;i<m;i++)
            dp2[b[i]]=0;
        printf("%d\n", ans);

    }
}
/*
6
3 3
1 2 3
3 2 1
10 5
1 23 2 32 4 3 4 5 6 1
1 2 3 4 5
1 1
2
1
1 1
2
1
10 5
1 23 2 32 4 3 4 5 6 1
1 2 3 4 5
3 3
1 2 3
3 2 1
*/
