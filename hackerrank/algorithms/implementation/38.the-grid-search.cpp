#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int R,r,C,c;

string solve(string a[],string b[]) {
    for(int i=0;i<=R-r;i++) {
        for(int j=0;j<=C-c;j++) {
            if(a[i][j]==b[0][0]) {
                bool flag=true;
                for(int x=0;x<r;x++) {
                    for(int y=0;y<c;y++) {
                        if(!flag) break;
                        if(a[i+x][j+y]!=b[x][y])
                            flag=false;
                    }
                    if(!flag) break;
                }
                if(flag) return "YES";
            }
        }
    }
    return "NO";
}
int main(){
    cin>>t;
    string a[1111],b[1111];
    while(t--) {
        cin>>R>>C;
        for(int i=0;i<R;i++) {
            cin>>a[i];
        }
        cin>>r>>c;
        for(int i=0;i<r;i++) {
            cin>>b[i];
        }
        cout<<solve(a,b)<<endl;

    }
}
