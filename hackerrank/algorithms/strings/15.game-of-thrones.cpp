#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    int m[26];
    int flag=0;
    cin>>s;
    memset(m,0,sizeof(m));
    for(int i=0;i<s.length();i++)
        m[s[i]-'a']++;
    for(int i=0;i<26;i++) {
        if(m[i]&1)
            flag++;
    }
    if(flag>=2)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

}
