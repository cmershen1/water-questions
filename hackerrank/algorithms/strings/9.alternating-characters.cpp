#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        int ans=0;
        for(int i=1;i<s.length();i++) {
            if(s[i]==s[i-1])
                ans++;
        }
        cout<<ans<<endl;
    }
}
