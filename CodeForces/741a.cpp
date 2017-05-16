#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[111];
int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b) {
    return a*b/gcd(a,b);
}
int dfs(int u, int sz,int rt) {
    int temp=a[u];
    a[u]=0;
    if(temp==rt)
        return sz;
    else if(u)
        return dfs(temp,sz+1,rt);
    else
        return 0;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++) {
        if(a[i]) {
            int size=dfs(i,1,i);
            if(size) {
                if(!(size&1))
                    size=size>>1;
                ans=lcm(ans,size);
            } else {
                ans=-1;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
