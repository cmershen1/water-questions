#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T,n,m;

int x[105][105];
int a[105];
void pre() {
    x[0][0]=a[0];
    for(int i=1;i<n;i++)
        x[0][i]=x[0][i-1]^a[i];

    for(int i=1;i<n;i++) {
        for(int j=i;j<n;j++) {
            x[i][j]=x[0][j]^x[0][i-1];
        }
    }
}
int main() {
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        pre();
        scanf("%d",&m);
        while(m--) {
            int q;
            scanf("%d",&q);
            int b=123456,l=-1;
            for(int i=0;i<n;i++) {
                for(int j=i;j<n;j++) {
                    if(abs(x[i][j]-q)<b) {
                        b=abs(x[i][j]-q);
                        l=j-i+1;
                    }
                    else if(abs(x[i][j]-q)==b) {
                        if(j-i+1>l)
                            l=j-i+1;
                    }
                }
            }
            printf("%d\n", l);
        }
        printf("\n");
    }

}
