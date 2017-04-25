#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin>>n;
    int ans1=99,ans2=99;
    for(int i=0;i*6<=n;i++) {
        for(int j=0;i*6+j*8<=n;j++) {
            if(i*6+j*8==n) {
                if(i+j<ans1+ans2) {
                    ans1=i;ans2=j;
                }
            }
        }
    }
    if(ans1*6+ans2*8==n)
        cout<<ans1+ans2<<endl;
    else
        cout<<-1<<endl;
}
