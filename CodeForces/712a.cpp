#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d",&n);
    int a[100005];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++) {
        printf("%d ", a[i]+a[i+1]);
    }
    printf("%d\n", a[n-1]);
}
