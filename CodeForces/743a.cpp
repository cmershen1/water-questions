#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c[100005];
int main() {
    int a,b,n;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    if(c[a]==c[b])
        cout<<0<<endl;
    else {
        cout<<1<<endl;
    }

}
