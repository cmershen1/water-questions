#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string s;
int main(){
    cin>>t;
    while(t--) {
        cin>>s;
        int i=0,j=s.length()-1,ans=0;
        while(i<j) {
            if(s[i]!=s[j])
                ans+=max(s[i],s[j])-min(s[i],s[j]);
            i++;j--;
        }
        cout<<ans<<endl;
    }
}
