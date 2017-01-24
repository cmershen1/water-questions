#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t,n;
    string s;
    int m[30];
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s;
        memset(m,0,sizeof(m));
        bool flag=0;
        for(int i=0;i<n;i++) {
            if(s[i]!='_')
                m[s[i]-'A']++;
            else
                m[27]++;
        }
        for(char i='A';i<='Z';i++) {
            if(m[i-'A']==1) {
                flag=1;
                break;
            }
        }
        if(m[27]) {
            puts(flag?"NO":"YES");
            continue;
        }
        for(int i=1;i<n-1;i++) {
            if(s[i]!=s[i-1] && s[i]!=s[i+1]) {
                flag=1;
                break;
            }
        }
        puts(flag?"NO":"YES");
    }
}
