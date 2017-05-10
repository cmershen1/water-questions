#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    int l[100005], r[100005];
    cin>>n;
    int lr=0;
    for(int i=1;i<=n;i++) {
        cin>>l[i]>>r[i];
        lr+=l[i]-r[i];
    }
    int max_beauty = abs(lr);
    int index = 0;
    for(int i=1;i<=n;i++) {
        int newlr=lr-2*l[i]+2*r[i];
        if(abs(newlr)>abs(max_beauty)) {
            max_beauty = newlr;
            index = i;
        }
    }
    cout<<index<<endl;
}
