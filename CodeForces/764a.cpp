#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}
int lcm(int a, int b) {
    return a*b/gcd(a,b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,z;
    while(cin>>n>>m>>z) {
        cout<<z/lcm(n,m)<<endl;
    }
}
