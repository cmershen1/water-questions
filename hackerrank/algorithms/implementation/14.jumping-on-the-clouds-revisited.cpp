#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int c[30];
int main(){
    int e=100;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&c[i]);
    }
    for(int i=0;i<n;i+=k) {
        if(c[i]) e-=3;
        else e--;
    }
    printf("%d\n",e);
}
