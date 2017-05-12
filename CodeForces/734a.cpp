#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    char c;
    cin>>n;
    int a=0;
    while(n--) {
        cin>>c;
        if(c=='A')
            a++;
        else if(c=='D')
            a--;
    }
    if(a>0)
        cout<<"Anton"<<endl;
    else if(a<0)
        cout<<"Danik"<<endl;
    else
        cout<<"Friendship"<<endl;
}
