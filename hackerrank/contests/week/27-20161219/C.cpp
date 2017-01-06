#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2222][2222];
int n,q;
int main(){
    cin>>n>>q;
    for(ll i=1;i<=n;i++) {//用int会爆！！
        for(ll j=1;j<=n;j++) {
            ll temp = i*j*i*j;
            a[i][j]=(temp%7==1)||(temp%7==3)||(temp%7==6)||(temp%7==0);
        }
    }
    int ans1=0,ans2=0,ans3=0;//90 180 270
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[n-j+1][i]!=a[i][j])
                ans1++;
            if(a[n-i+1][n-j+1]!=a[i][j])
                ans2++;
            if(a[j][n-i+1]!=a[i][j])
                ans3++;
        }
    }
    while(q--) {
        int x;
        cin>>x;
        if(x%360==90)
            cout<<ans1<<endl;
        else if(x%360==180)
            cout<<ans2<<endl;
        else if(x%360==270)
            cout<<ans3<<endl;
        else
            cout<<0<<endl;
    }
}
