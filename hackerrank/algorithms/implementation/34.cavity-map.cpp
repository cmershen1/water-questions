#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    string s[111];
    bool vis[111][111];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<n-1;j++) {
            if(s[i][j]>s[i-1][j] && s[i][j]>s[i+1][j] && s[i][j]>s[i][j-1] && s[i][j]>s[i][j+1])
                vis[i][j]=1;
        }
    }
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<n-1;j++) {
            if(vis[i][j])
                s[i][j]='X';
        }
    }
    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
}
