#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    cout<<3*(1LL<<(int)(floor(log2((t+2)/3))+1))-t-2<<endl;
}
