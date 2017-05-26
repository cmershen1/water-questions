#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    string s;
    cin>>n>>s;
    string ans="";
    ans+=s[0];

    bool flag = (n&1);
    for(int i=1;i<n;i++) {
        if(flag)
            ans=s[i]+ans;
        else
            ans=ans+s[i];
        flag=!flag;
    }
    cout<<ans<<endl;
}
