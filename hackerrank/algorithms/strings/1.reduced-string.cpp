#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    for(int i=1;i<s.length();i++) {
        if(s[i]==s[i-1]) {
            s=s.substr(0,i-1)+s.substr(i+1);
            i=0;
        }
    }
    if(s="")
        cout<<"Empty String"<<endl;
    else
        cout<<s<<endl;

}
