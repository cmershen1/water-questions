#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,ans=1;
int a[100005];
int main() {
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<n;i++) {
        if(a[i]-a[i-1]<=c)
            ans++;
        else
            ans=1;
    }
    printf("%d\n", ans);
}
 
