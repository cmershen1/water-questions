#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d1,m1,y1,d2,m2,y2;
int main(){
    cin>>d1>>m1>>y1;
    cin>>d2>>m2>>y2;
    int ans=0;
    if(y1>y2) {
        ans=10000;
    }
    else if(y1==y2) {
        if(m1>m2)
            ans=500*(m1-m2);
        else if(m1==m2) {
            if(d1>d2)
                ans=15*(d1-d2);
        }
    }
    cout<<ans<<endl;
}
