#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
ll ans=0;
const int M=10007;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        ans=(ans+(a[i]%M*a[n-1-i]%M))%M;
    }
    printf("%I64d\n", ans%M);
}
