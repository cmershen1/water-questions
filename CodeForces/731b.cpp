#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200001];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int flag=1;
    for(int i=n-1;i>=1;i--) {
        if(a[i]<0) {
            flag=0;
            break;
        }

        if(a[i]&1)
            a[i-1]--;
    }
    if(a[0]^1)
        flag=0;
    if(!flag)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}
