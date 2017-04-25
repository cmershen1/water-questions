#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
int m[123];
int main(){
    memset(m,0,sizeof(m));
    cin>>n;
    int mx=0;
    for(int i=0;i<n;i++) {
        cin>>a;
        m[a]++;
        mx=max(mx,m[a]);
    }
    cout<<n-mx<<endl;
}
