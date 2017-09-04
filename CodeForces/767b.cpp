#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ts,tf,t,n,a;
ll wait = 1e13,ans = 1e13;
int main() {
    cin>>ts>>tf>>t>>n;
    while(n--) {
        cin>>a;
        if (a>0 && a+t<=tf) {
            if (max(ts, a-1) <= tf-t && ts-a+1 < wait) {
                wait = ts-a+1;
                ans = min(ts, a-1);
            }
            ts = max(ts, a) + t;
        }
    }

    if(ts+t <= tf)
        ans = ts;
    cout<<ans<<endl;

}
