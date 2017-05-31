#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    while(cin>>n) {
        cout<<n/2<<endl;
        while(n>3) {
            cout<<"2 ";
            n-=2;
        }
        cout<<n<<endl;
    }
}
