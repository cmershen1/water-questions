#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    ll x,y,z,b,w;
    cin>>t;
    while(t--) {
        cin>>b>>w;
        cin>>x>>y>>z;
        cout<<min(b*x+w*y,(b+w)*y+z*b,(b+w)*x+z*w);
    }
}
