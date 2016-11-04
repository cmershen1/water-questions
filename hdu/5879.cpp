#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double f[110300];
char s[1111];
void pre() {
    f[0]=0.0;
    f[1]=1.0;
    ll i=2;
    while(i<110300) {
        f[i]=f[i-1]+1.0/(i*i);
        i++;
    }
}
int main() {
    pre();
    while(scanf("%s",s)!=EOF) {
        if(strlen(s)>=7) {
            printf("1.64493\n");
        }
        else {
            int a;
            sscanf(s,"%d",&a);
            if(a>=110293)
                printf("1.64493\n");
            else
                printf("%.5lf\n", f[a]);
        }
    }
}
