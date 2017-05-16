#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime(int n) {
    if(n==2)
        return true;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0)
            return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;

    if(isPrime(n))
        cout<<1<<endl;
    else if(n&1) {
        if(isPrime(n-2))
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
    else
        cout<<2<<endl;

}
