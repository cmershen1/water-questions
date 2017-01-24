//这道题正解是线段树 可是直接模拟也过了
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,a,b;
int w[100005];
int main(){
    cin>>n>>t;
    for(int i=0;i<n;i++) {
        cin>>w[i];
    }
    while(t--) {
        cin>>a>>b;
        int m=4;
        for(int i=a;i<=b;i++)
            m=min(m,w[i]);
        cout<<m<<endl;
    }
}
