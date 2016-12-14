#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t,n,m,c;
    cin>>t;
    while(t--) {
        cin>>n>>c>>m;
        if((n*m)%((m-1)*c))
            cout<<n*m/((m-1)*c)<<endl;
        else
            cout<<n*m/((m-1)*c)-1<<endl;
    }
}
