#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN],c[MAXN],s[MAXN];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        memset(s, 0, sizeof(s));
        cnt=0;
        for(int i=1;i<n;i++) {
            cin>>a[i]>>b[i];
        }
        for(int i=1;i<=n;i++) {
            cin>>c[i];
        }

        for(int i=1;i<n;i++) {
            if(c[a[i]] != c[b[i]]) {
                s[a[i]]++;
                s[b[i]]++;
                cnt++;
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++) {
            if(cnt==s[i]) {
                ans=i;
                break;
            }
        }
        if(ans==-1)
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
    }
}
