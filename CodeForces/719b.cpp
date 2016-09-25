#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[100005];
int main() {
    scanf("%d",&n);
    scanf("%s",s);
    int ans1=0,ans2=0;
    int t1=0,t2=0;
    for(int i=0;i<n;i++) { //brbrbr...
        if(i&1) {//r
            if(s[i]=='b')
                t1++;
        }
        else {// b
            if(s[i]=='r')
                t2++;
        }
    }
    ans1=max(t1,t2);
    t1=0;t2=0;
    for(int i=0;i<n;i++) { //rbrbrb...
        if(i&1) {//b
            if(s[i]=='r')
                t1++;
        }
        else {// r
            if(s[i]=='b')
                t2++;
        }
    }
    ans2=max(t1,t2);
    printf("%d\n", min(ans1,ans2));
}
