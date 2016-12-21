#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string s;
int m1[26],m2[26];
int main(){
    cin>>t;
    while(t--) {
        cin>>s;
        if(s.length()&1) {
            cout<<-1<<endl;
        }
        else {
            int n=s.length()/2;
            string s1=s.substr(0,n);
            string s2=s.substr(n);
            memset(m1,0,sizeof(m1));
            memset(m2,0,sizeof(m2));
            for(int i=0;i<n;i++) {
                m1[s1[i]-'a']++;
                m2[s2[i]-'a']++;
            }
            int ans=0;
            for(int i=0;i<26;i++) {
                ans+=abs(m1[i]-m2[i]);
            }
            cout<<ans/2<<endl;
        }
    }
}
