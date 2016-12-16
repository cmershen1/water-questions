#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,k,b;
void solve() {
    if(b*(b+1)/2>n || (2*k-b+1)*b/2<n) //这里会爆ll，怎么解决？？？？换语言大法好！！
        cout<<-1<<endl;
    else {
        ll ans[100005];
        for(int i=1;i<=b;i++) {
            ans[i]=i;
        }
        ll diff=n-b*(b+1)/2;
        ll p=b;//正在改变位置p的数
        ll a=k;//这一位允许的最大数
        while(diff>0) {
            if(diff<=a-ans[p]) {
                ans[p]+=diff;
                diff=0;
            }
            else {
                diff-=a-ans[p];
                ans[p]=a;
                p--;a--;
            }
        }
        for(int i=1;i<b;i++) {
            cout<<ans[i]<<' ';
        }
        cout<<ans[b]<<endl;
    }
}
int main(){
    cin>>t;
    while(t--) {
        cin>>n>>k>>b;
        solve();
    }
}
