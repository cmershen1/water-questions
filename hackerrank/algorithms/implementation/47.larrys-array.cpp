#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t,n;
    int a[1005];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }

        int x=1;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                // if(a[i]>a[j])
                //     x++;
                x^=(a[i]>a[j]);
            }
        }
        if(x)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
