#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    int p[10005];
    int l,r,x;

    while (cin>>n>>m) {
        for (int i=1; i<=n; i++) {
            cin >> p[i];
        }
        while(m--) {
            cin>>l>>r>>x;
            int cnt=l;
            for(int i=l; i<=r; i++) {
                if(p[i]<p[x])
                    cnt++;
            }
            if (cnt==x) cout<<"Yes"<<endl;
            else cout<<"No" <<endl;
        }
    }

}
