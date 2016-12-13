#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    k=k%n;
    for(int i=0;i<q;i++) {
        int x;
        scanf("%d",&x);
        if(x<k)
            printf("%d\n", a[n-k+x]);
        else
            printf("%d\n", a[x-k]);
    }

}
