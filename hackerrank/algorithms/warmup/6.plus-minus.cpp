#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,t;
    int a=0,b=0,c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&t);
        if(t>0) a++;
        else if(t<0) b++;
        else c++;
    }
    printf("%.6lf\n%.6lf\n%.6lf", a*1.0/n,b*1.0/n,c*1.0/n);
}
