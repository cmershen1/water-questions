#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        bool flag=true;
        for(int i=1;i<s.length();i++) {
            if(abs(s[i]-s[i-1])!=abs(s2[i]-s2[i-1])) {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"Funny"<<endl;
        else
            cout<<"Not Funny"<<endl;
    }
}
