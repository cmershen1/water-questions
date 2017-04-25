#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){

    int n;
    scanf("%d",&n);
    int a=0,b=5;
    for(int i=1;i<=n;i++) {
        a+=b/2;
        b=(b/2)*3;
    }
    printf("%d\n", a);
}
