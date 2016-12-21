#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string a,b;
int m1[26],m2[26];
int main(){
    cin>>t;
    while(t--) {
        cin>>a>>b;
        memset(m1,0,sizeof(m1));
        memset(m2,0,sizeof(m2));
        for(int i=0;i<a.length();i++) {
            m1[a[i]-'a']++;
        }
        for(int i=0;i<b.length();i++) {
            m2[b[i]-'a']++;
        }
        bool flag=false;
        for(int i=0;i<26;i++) {
            if(m1[i]>0 && m2[i]>0)
                flag=true;
        }
        puts(flag?"YES":"NO");
    }
}
