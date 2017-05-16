#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    switch (n%4) {
        case 0:
            cout<<0<<endl;
            return 0;
        case 1:
            cout<<min(c,min(a+b,3*a))<<endl;
            return 0;
        case 2:
            cout<<min(2*a,min(b,2*c))<<endl;
            return 0;
        case 3:
            cout<<min(a,min(b+c,c*3))<<endl;
            return 0;
    }
}
