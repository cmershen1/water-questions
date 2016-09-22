#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans=0;
int main() {
    scanf("%d",&n);
    for(int i=0;i*i<=n;i++) {
        int j=sqrt(n-i*i);
        if(i*i+j*j==n) {
            if(i==0 || j==0)
                ans+=2;
            else
                ans+=4;
        }
    }
    printf("%d\n", ans);
}
