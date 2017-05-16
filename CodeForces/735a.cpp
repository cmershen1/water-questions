#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int g,t;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='G')
            g=i;
        if(s[i]=='T')
            t=i;
    }
    bool ans=true;
    if(g<t) {
        for(int i=g;i<=t;i+=k) {
            if((i+k>t && i<t) || s[i]=='#') {
                ans=false;
                break;
            }
        }
    } else {
        for(int i=g;i>=t;i-=k) {
            if((i-k<t && i>t) || s[i]=='#') {
                ans=false;
                break;
            }
        }
    }
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
