#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
int m1[26],m2[26];
int main(){
    cin>>a>>b;
    memset(m1,0,sizeof(m1));
    memset(m2,0,sizeof(m2));
    int ans=0;
    for(int i=0;i<a.length();i++)
        m1[a[i]-'a']++;
    for(int i=0;i<b.length();i++)
        m2[b[i]-'a']++;

    for(int i=0;i<26;i++) {
        ans+=abs(m1[i]-m2[i]);
    }
    cout<<ans<<endl;
}
