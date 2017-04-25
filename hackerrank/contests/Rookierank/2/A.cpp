#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin>>n;
    int cnt=1,m=1;
    while(m) {
        m=(m*10+1)%n;
        cnt++;
    }
    cout<<cnt<<endl;
}
