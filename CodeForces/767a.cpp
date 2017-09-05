#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x=n;
    for(int i=1;i<=n;i++) {
        int t;
        cin>>t;
        a[t]=1;
        while(a[x]==1)
            cout<<x--<<' ';
        cout<<endl;
    }
}
