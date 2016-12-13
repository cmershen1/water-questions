#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
int main(){
    int n;
    cin>>n;
    int a[1111];
    map<int,int> m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int ans=INF;
    for(int i=0;i<n;i++) {
        if(m.find(a[i])!=m.end())
            ans=min(ans,i-m[a[i]]);
        m[a[i]]=i;
    }
    cout<<((ans==INF)?-1:ans)<<endl;
}
