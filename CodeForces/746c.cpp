#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int s,x1,x2,t1,t2,p,d;
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    if(t1>t2) {
        cout<<t2*abs(x1-x2)<<endl;//人比车快就直接走路
        return 0;
    }

    int res=0;
    bool flag=false;
    int res1=t2*abs(x1-x2);
    if(d==1) {
        if(p<=x1 && x1<x2)
            res=(x2-p)*t1;//人随车到
        else if(x1<x2)
            res=(2*s+x2-p)*t1;
        else if(x2<x1)
            res=(2*s-x2-p)*t1;
    } else {
        if(p>=x1 && x1>x2) {
            res=(p-x2)*t1;
        } else if(x1>x2) {
            res=(2*s-x2+p)*t1;
        } else
            res=(p+x2)*t1;
    }
    cout<<min(res,res1)<<endl;
}
