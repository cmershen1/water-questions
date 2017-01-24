#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,a,b;
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d %d",&a,&b);
        printf("%.0f\n", floor(sqrt(b*1.0))-ceil(sqrt(a*1.0))+1);
    }
}
