#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,a,b;
    cin>>k>>a>>b;
    if(a<b)
        swap(a,b);
    if(b<k) {
        if(a%k) {
            cout<<-1<<endl;
            return 0;
        }
    }
    int x=a/k+b/k;
    if(x==0)
        cout<<-1<<endl;
    else
        cout<<x<<endl;
}
