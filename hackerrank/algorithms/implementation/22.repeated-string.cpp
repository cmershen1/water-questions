#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[123];
ll n;
int main(){
    scanf("%s",s);
    scanf("%lld",&n);
    int a=0,l=strlen(s);
    for(int i=0;s[i];i++) {
        if(s[i]=='a')
            a++;
    }
    ll ans=0;
    ans+=n/l*a;
    for(int i=0;i<n%l;i++) {
        if(s[i]=='a')
            ans++;
    }
    printf("%lld\n", ans);
}
