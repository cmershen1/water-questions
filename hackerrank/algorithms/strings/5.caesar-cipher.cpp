#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string s;
int main(){
    cin>>n;
    cin>>s;
    cin>>k;
    k=k%26;
    for(int i=0;i<n;i++) {
        if(s[i]>='a' && s[i]<='z')  {
            if(s[i]+k>'z')
                s[i]+=k-26;
            else
                s[i]+=k;
        }
        else if(s[i]>='A' && s[i]<='Z')  {
            if(s[i]+k>'Z')
                s[i]+=k-26;
            else
                s[i]+=k;
        }

    }
    cout<<s<<endl;
}
