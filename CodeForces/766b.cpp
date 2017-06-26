#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(a,a+n);
        bool flag=false;
        for(int i=0;i+2<n;i++) {
            if(a[i]+a[i+1]>a[i+2]) {
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout << "NO" << endl;
    }
        
}
