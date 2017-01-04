#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int c[111];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    if(n==1)
        cout<<c[0]*2<<' '<<1<<endl;
    else {
        sort(c,c+n);
        if(c[0]!=c[1]) {
            cout<<min(c[0]*2,c[1])<<' '<<1<<endl;
        }
        else {
            cout<<c[0]<<' '<<n<<endl;
        }
    }
}