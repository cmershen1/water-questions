#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,t,a,b,m,n;
int da[100005],db[100005];
int main(){
    scanf("%d %d\n%d %d\n%d %d\n",&s,&t,&a,&b,&m,&n);
    int c1=0,c2=0;
    for(int i=0;i<m;i++) {
        scanf("%d",&da[i]);
        if(da[i]+a>=s && da[i]+a<=t)
            c1++;
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&db[i]);
        if(db[i]+b>=s && db[i]+b<=t)
            c2++;
    }
    printf("%d\n%d\n", c1,c2);

}
