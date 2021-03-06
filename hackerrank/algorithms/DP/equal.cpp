#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[10005];

int solve(int a){
    int ans=0;
    for(int i=0;i<n;i++){
        int temp=x[i]-a;
        ans+=temp/5+temp%5/2+temp%5%2;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int mi=1000;
        for(int i=0;i<n;i++) {
            cin>>x[i];
            mi=min(mi,x[i]);
        }
        int res=1e9;
        for(int i=0;i<5;i++)
            res=min(res,solve(mi-i));
        cout<<res<<endl;
    }
    return 0;
}
