#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    if(x3-x1!=x2+x4)
        cout<<"No"<<endl;
    else
        cout<<(x1+x3)/2<<' '<<(x2+x4)/2<<' '<<(x4-x2)/2<<endl;
}
