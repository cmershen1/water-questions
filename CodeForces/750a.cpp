#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,k;
    while(cin>>n>>k) {
        int x=0;
        while(5*x*(x+1)<=2*(240-k))
            x++;
        cout<<min(x-1,n)<<endl;
    }

}
