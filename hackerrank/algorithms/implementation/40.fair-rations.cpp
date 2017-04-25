#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,b=0,flag=-1,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        if(b&1) {
            if(flag!=-1) {
                ans+=(i-flag)*2;
                flag=-1;
            }
            else
                flag=i;
        }
    }
    if(flag!=-1)
        cout<<"NO"<<endl;
    else
        cout<<ans<<endl;
}
