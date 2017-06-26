#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin>>s) {
        int m[30];
        int pos[30];
        memset(m,0,sizeof(m));
        memset(pos,0,sizeof(pos));
        for(int i=0;i<s.length();i++) {
            m[s[i]-'a']++;
            if(m[s[i] - 'a']==1)
                pos[s[i]-'a'] = i;
        }
        bool flag=true;
        int i;
        for(i=0;i<s.length();i++) {
            if(m[i]==0)
                break;
        }
        for(int j=i;j<26;j++) {
            if(m[j]!=0) {
                flag=false;
                break;
            }
        }

        int max=-1;
        for(int j=0;j<i;j++) {
            if(pos[j]<max) {
                flag=false;
                break;
            }
            max=pos[j];
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
