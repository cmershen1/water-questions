#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++) {
        if(i%3==0 || i%3==2) {
            if(s[i]!='S') {
                ans++;
            }
        }
        else
        {
            if(s[i]!='O') {
                ans++;
            }
        }

    }
    cout<<ans<<endl;
}
