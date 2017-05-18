#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    ll k;
    cin>>n>>k;
    for(int i=0;i<62;i++) {
        if((1LL<<i)&k) {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}
