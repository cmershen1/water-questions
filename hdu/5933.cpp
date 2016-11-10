#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
int T,n,k;
stack<ll> s;
ll a[100005];
ll sum;
int main() {
    //RE("in.txt");
    //WR("out.txt");
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d %d",&n,&k);
        sum=0;
        for(int i=1;i<=n;i++) {
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        if(sum%k) {
            printf("Case #%d: -1\n",t);
        }
        else {
            for(int i=n;i>=1;i--) {
                s.push(a[i]);
            }
            int ans=0;ll target=sum/k;
            ll cur=0;
            while(!s.empty()) {
                cur+=s.top();
                s.pop();
                if(cur==target) {
                    cur=0;
                }
                else if(cur<target) {
                    while(cur<target) {
                        cur+=s.top();
                        s.pop();
                        ans++;
                    }
                    if(cur==target) {
                        cur=0;
                    }
                    else {
                        if(cur%target) {
                            ans+=cur/target;
                            s.push(cur%target);
                        }
                        else {
                            ans+=cur/target-1;
                        }
                        cur=0;
                    }
                }
                else {
                    if(cur%target) {
                        ans+=cur/target;
                        s.push(cur%target);
                    }
                    else {
                        ans+=cur/target-1;
                    }
                    cur=0;
                }
            }
            printf("Case #%d: %I64d\n",t,ans);
        }
    }
}
