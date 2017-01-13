#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p;
int a[100005];
int main(){
    cin>>n>>p;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(ceil(a[i]*1.0/p));
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++) {
        if(v[i]<=v[i-1])
            v[i]=v[i-1]+1;
    }
    ll sum=0;
    for(int i=0;i<n;i++) {
        sum+=v[i];
    }
    cout<<sum<<endl;
}
