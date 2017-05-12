#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int k2,k3,k5,k6;
    cin>>k2>>k3>>k5>>k6;

    int a1=min(k3,k2);
    k3-=a1;k2-=a1;
    int a2=min(k2,min(k5,k6));
    int ans1=a1*32l+a2*256l;
    k3+=a1;k2+=a1;


    a1=min(k2,min(k5,k6));
    k2-=a1;k5-=a1;k6-=a1;
    a2=min(k3,k2);
    int ans2=a1*256l+a2*32l;

    cout<<max(ans1,ans2)<<endl;
}
