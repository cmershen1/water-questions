#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,c;
ll sum=0,b;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&c);
        if(i!=k)
            sum+=c;
    }
    scanf("%lld",&b);
    if(b*2==sum)
        printf("Bon Appetit\n");
    else {
        printf("%lld\n", b-sum/2);
    }
}
