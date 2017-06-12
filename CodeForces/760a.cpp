#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(int m) {
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        return 31;
    else if(m==4 || m==6 || m==9 || m==11)
        return 30;
    else
        return 28;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,d;
    
    while(cin>>m>>d) {
        cout<<(f(m)+d-2)/7+1<<endl;
    }
}
