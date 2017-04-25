#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    string s[105];
    int m[105][26];
    memset(m,0,sizeof(m));
    for(int i=0;i<n;i++) {
        cin>>s[i];
        for(int j=0;j<s[i].length();j++) {
            int u=s[i][j]-'a';
            m[i][u]++;
        }
    }
    int ans=0;
    for(int i=0;i<26;i++) {
        bool flag=true;
        for(int j=0;j<n;j++) {
            if(!m[j][i]) {
                flag=false;
                break;
            }
        }
        if(flag)
            ans++;
    }
    cout<<ans<<endl;
}
