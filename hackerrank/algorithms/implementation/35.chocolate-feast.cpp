#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
<<<<<<< HEAD
    int t,n,c,m;
    cin>>t;
    while(t--) {
        cin>>n>>c>>m;
        int x=n/c,y=x; //x个皮，y个巧克力
        int ans=0;
        do{
            ans+=y;
            y=x/m;
            x=y+x%m;
        }while(x>=m);
        cout<<ans+y<<endl;//循环出来的时候还有y个巧克力没吃，加上
    }

=======
    int t,n,m,c;
    cin>>t;
    while(t--) {
        cin>>n>>c>>m;
        if((n*m)%((m-1)*c))
            cout<<n*m/((m-1)*c)<<endl;
        else
            cout<<n*m/((m-1)*c)-1<<endl;
    }
>>>>>>> origin
}
