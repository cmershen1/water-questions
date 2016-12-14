#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,t;
int main(){
    cin>>n>>k;
    int page=1,chap=1,cnt=0;
    for(int i=1;i<=n;i++) {
        cin>>t;
        for(int j=1;j<=t;j++) {
            //cout<<"Chapter "<<i<<",Question "<<j<<", Page "<<page<<endl;
            if(j==page)
                cnt++;
            if(j%k==0)
                page++;
        }
        if(t%k)
            page++;
    }
    cout<<cnt<<endl;

}
