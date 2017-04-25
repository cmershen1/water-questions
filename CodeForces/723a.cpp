#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int x1,x2,x3;
    scanf("%d %d %d",&x1,&x2,&x3);
    int ans=305;
    for(int i=1;i<=100;i++) {
        ans=min(abs(x1-i)+abs(x2-i)+abs(x3-i),ans);
    }
    printf("%d\n", ans);
}
