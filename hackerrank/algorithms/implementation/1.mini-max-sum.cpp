#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a[5],sum=0;
    for(int i=0;i<5;i++) {
        scanf("%I64d",&a[i]);
        sum+=a[i];
    }
    sort(a,a+5);
    printf("%I64d %I64d\n", sum-a[4],sum-a[0]);
}
