#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int c[123];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i];
    int ans=0;
    int i=0;
    while(i<n-1) {
        if(c[i+2]==0) {
            ans++;
            i+=2;
            continue;
        }
        else {
            ans++;
            i++;
            continue;
        }
    }
    cout<<ans<<endl;
}
