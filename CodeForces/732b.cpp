#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,k;
    int a[501];
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<n;i++) {
        int d=k-a[i]-a[i-1];
        if(d>0) {
            a[i]+=d;
            ans+=d;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n-1;i++) {
        cout<<a[i]<<' ';
    }
    cout<<a[n-1]<<endl;
}
