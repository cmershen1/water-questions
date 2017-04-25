#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
char s[11];
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%s",s);
        int num = atoi(s);
        int cnt=0;
        for(int i=0;s[i];i++) {
            if(s[i]!='0' && num%(s[i]-'0')==0)
                cnt++;
        }
        printf("%d\n", cnt);
    }
}
