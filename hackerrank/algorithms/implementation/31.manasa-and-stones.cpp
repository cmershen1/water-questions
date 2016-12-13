#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t,n,a,b;
    cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        set<int> s;
        if(a==b) {
            cout<<(n-1)*a<<endl;
            continue;
        }
        for(int x=0;x<n;x++) {
            s.insert(x*a+(n-1-x)*b);
        }
        for(set<int>::iterator i=s.begin();i!=s.end();i++)
            cout<<*i<<" ";
        cout<<endl;
    }
}
