#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    int cur=0;
    int ans=0;
    for(int i=0;i<s.length();i++) {
        int next=s[i]-'a';
        int ad=min(26-abs(cur-next), abs(cur-next));
        cur=next;
        ans+=ad;
    }
    cout<<ans<<endl;
}
