#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int a[100005];
int b[100005];
int lowbit(int x) {
    return x&(-x);
}
void update(int i) {
    while(i<=n) {
        b[i]++;
        i+=lowbit(i);
    }
}
int get(int i) {
    int s=0;
    while(i>0) {
        s+=b[i];
        i-=lowbit(i);
    }
    return s;
}
int main(){
    cin>>t;
    while (t--) {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(b,0,sizeof(b));
        bool flag=true;
        int ans=0;
        for(int i=n;i>=1;i--) {
            if(get(a[i])>2) {
                flag=false;
                break;
            }
            ans+=get(a[i]);
            update(a[i]);
        }

        if(flag)
            cout<<ans<<endl;
        else
            cout<<"Too chaotic"<<endl;


    }
}
