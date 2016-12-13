#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string s[500];
int f(string a,string b) {
    int cnt=0;
    for(int i=0;i<a.length();i++) {
        if(a[i]=='1' || b[i]=='1')
            cnt++;
    }
    return cnt;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }
    int ans1=0,ans2=0,mx=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int cnt=f(s[i],s[j]);
            if(cnt==ans1) {
                ans2++;
            }
            else if(cnt>ans1) {
                ans1=cnt;
                ans2=1;
            }
        }
    }
    cout<<ans1<<endl<<ans2<<endl;
}
