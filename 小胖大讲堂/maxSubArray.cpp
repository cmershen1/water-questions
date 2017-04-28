#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int a[10000];
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int dp=INT_MIN;
    int m=INT_MIN;
    for(int i=0;i<n;i++) {
        if(dp>0) {
            dp=dp+a[i];
        }
        else {
            dp=a[i];
        }
        m=max(dp,m);
    }
    cout<<m<<endl;
}
