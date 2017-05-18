#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,n1,n2;
    cin>>n>>n1>>n2;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    if(n1<n2) {
        swap(n1,n2);
    }
    double ans = 0.0;
    for(int i=0;i<n1+n2;i++) {
        if(i<n2) {
            ans+=a[i]*1.0/n2;
        } else {
            ans+=a[i]*1.0/n1;
        }
    }
    printf("%.6lf\n",ans);
}
