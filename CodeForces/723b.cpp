#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[300];
int n;
int main() {
    bool flag=false;//,end=true;
    int ans1=0,ans2=0;
    int cnt1=0,cnt2=0;
    scanf("%d\n",&n);
    scanf("%s",s);

    for(int i=0;i<n;i++) {
        printf("s[%d]=%c,ans1=%d,ans2=%d,cnt1=%d,cnt2=%d,flag=%d\n",i,s[i],ans1,ans2,cnt1,cnt2,flag );
        if(s[i]=='(') {
            cnt1=0;
            ans1=max(ans1,cnt1);
            flag=true;
        }
        else if(s[i]==')') {
            flag=false;
            if(s[i-1]!='_' && s[i-1]!='(')
                ans2++;
            cnt1=0;
            cnt2=0;
        }
        else if(s[i]=='_') {
            if(flag) {
                if(s[i-1]!='_' && s[i-1]!='(')
                    ans2++;
            }
            else {
                ans1=max(ans1,cnt1);
                cnt1=0;
            }
        }
        else {
            if(!flag) {
                cnt1++;
                ans1=max(ans1,cnt1);
            }
        }

    }

    printf("%d %d\n", ans1,ans2);
}
