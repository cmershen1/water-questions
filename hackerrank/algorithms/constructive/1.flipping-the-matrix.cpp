#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int m[300][300];
int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n*2;i++) {
            for(int j=0;j<n*2;j++) {
                cin>>m[i][j];
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int x1=i,x2=2*n-1-i;
                int y1=j,y2=2*n-1-j;
                ans+=max(max(m[x1][y1],m[x1][y2]),max(m[x2][y1],m[x2][y2]));
            }
        }
        cout<<ans<<endl;
    }
}
