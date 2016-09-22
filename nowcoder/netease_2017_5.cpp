#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rev(int x) {
    int r=0;
    while(x) {
        r*=10;
        r+=x%10;
        x/=10;
    }
    return r;
}
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    int ans=rev(rev(x)+rev(y));
    cout<<ans<<endl;
}
