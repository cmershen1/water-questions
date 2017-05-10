#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f(char c) {
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y';
}
int main() {
    string a;
    cin>>a;
    a='A'+a+'A';
    int ans=-1;
    int n=a.length();
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(f(a[i]) && f(a[j])) {
                ans=max(j-i,ans);
                break;
            }
        }
    }
    cout<<ans<<endl;
}
