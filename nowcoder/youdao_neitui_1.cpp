#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int card[205][205];
int main() {
    int T,n,k;
    scanf("%d",&T);
    while(T--) {
        memset(card,0,sizeof(card));
        scanf("%d %d",&n,&k);
        for(int i=0;i<n*2;i++) {
            scanf("%d",&card[0][i]);
        }
        for(int i=1;i<=k;i++) {
            for(int j=0;j<n*2;j++) {
                if(j<n)
                    card[i][j*2]=card[i-1][j];
                else
                    card[i][j*2-(n*2-1)]=card[i-1][j];
            }
        }
        for(int i=0;i<n*2-1;i++) {
            printf("%d ", card[k][i]);
        }
        printf("%d\n", card[k][n*2-1]);
    }
}
