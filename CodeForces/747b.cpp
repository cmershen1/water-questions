#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    string s;
    while(cin>>n>>s) {
        if(n%4) {
            cout<<"==="<<endl;
            continue;
        }
        map<char, int> m;
        bool flag=true;
        m['A']=m['G']=m['C']=m['T']=n/4;
        for(int i=0;i<s.length();i++) {
            if(s[i]!='?') {
                m[s[i]]--;
                if(m[s[i]]==-1)
                    flag=false;
            }
        }
        for(int i=0;i<s.length();i++) {
            if(s[i]=='?') {
                if(m['A']) {
                    s[i]='A';
                    m['A']--;
                }
                else if(m['G']) {
                    s[i]='G';
                    m['G']--;
                }
                else if(m['C']) {
                    s[i]='C';
                    m['C']--;
                }
                else if(m['T']) {
                    s[i]='T';
                    m['T']--;
                }
            }
        }
        if(flag)
            cout<<s<<endl;
        else
            cout<<"==="<<endl;
    }
}
