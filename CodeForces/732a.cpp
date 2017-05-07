#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int k,r;
    cin>>k>>r;
    int a=1;
    while(1) {
        if((k*a)%10 == 0 || (k*a)%10 == r)
            break;
        a++;
    }
    cout<<a<<endl;
}
