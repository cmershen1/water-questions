#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[5];
int main() {
    scanf("%d",&n);
    int i=0;
    while(n--) {
        scanf("%d",&m);
        if(i==0)
            a[i++]=m;
        else if(i==1) {
            if(a[0]!=m)
                a[i++]=m;
        }
        else if(i==2) {
            if(a[0]!=m && a[1]!=m)
                a[i++]=m;
        }
        else if(a[0]!=m && a[1]!=m && a[2]!=m) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(i<3) {

            cout<<"YES"<<endl;
            return 0;
    }
    sort(a,a+3);
    if(a[0]+a[2]==a[1]*2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
