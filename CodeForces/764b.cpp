#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005], b[200005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        if(n&1) {
	        for(int i=1;i<=n;i++) {
	            if(i&1)
	                cin>>a[n-i+1];
	            else
	                cin>>a[i];
	        }
        } else {
            for(int i=1;i<=n/2;i++) {
                if(i&1)
                    cin>>a[n-i+1];
                else
                    cin>>a[i];
            }
            for(int i=n/2+1;i<=n;i++) {
                if(i&1)
                    cin>>a[i];
                else
                    cin>>a[n-i+1];
            }
        }

        for(int i=1;i<n;i++) {
            cout<<a[i]<<' ';
        }
        cout<<a[n]<<endl;
    }
}
