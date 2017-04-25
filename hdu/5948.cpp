#include <bits/stdc++.h>
using namespace std;
int T,a,b;
int main() {
    scanf("%d",&T);
    while(t--) {
        scanf("%d%d",&a,&b);
        printf("%d\n", max(a*2+b,b*2+a));
    }

}
