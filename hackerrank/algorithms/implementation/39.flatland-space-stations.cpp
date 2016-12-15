#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    int a[100005];
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>a[i];
    }
    int mx=-1;
    sort(a,a+m);
    mx=max(a[0],n-1-a[m-1]);
    for(int i=1;i<m;i++) {
        mx=max(mx,(a[i]-a[i-1])/2);
    }
    cout<<mx<<endl;
}
