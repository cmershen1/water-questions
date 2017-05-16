#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    ll a=2,b=3;
    int cnt=1;
    while(a<n) {
        ll c=a+b;
        a=b;
        b=c;
        cnt++;
    }
    if(a>n)
        cnt--;
    cout<<cnt<<endl;
}
