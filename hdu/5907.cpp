#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
char s[100005];
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%s",&s);
        ll ans=0;
        int cnt=0;//统计当前延伸了几个q
        for(int i=strlen(s)-1;i>=0;i--) {
            if(s[i]=='q') {
                cnt++;
                ans+=cnt;
            }
            else
                cnt=0;
        }
        printf("%I64d\n",ans );
    }
}
