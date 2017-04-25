#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T;
char s[15];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s);
        int ans=0;
        for(int i=0;i<strlen(s);i++) {
            if(s[i]=='H') ans+=1;
            else if(s[i]=='O') ans+=16;
            else if(s[i]=='C') ans+=12;
        }
        printf("%d\n",ans );
    }
}
