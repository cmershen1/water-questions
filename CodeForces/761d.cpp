#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,r;
int a[100005],p[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n>>l>>r) {
        map<int,int> m;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++) {
            cin>>p[i];
            m[p[i]]=i;
        }

        vector<int> b(n+1, 0);
        int pre=m[1];
        b[pre]=l;
        bool flag=true;
        for(int i=2;i<=n;i++) {
            int cur=m[i];
            b[cur]=max(l, b[pre]-a[pre]+a[cur]+1);
            if(b[cur]>r) {
                flag=false;
                break;
            }
            pre=cur;
        }
        if(flag) {
            for(int i=1;i<=n;i++) {
                cout<<b[i]<<' ';
            }
            cout<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}
