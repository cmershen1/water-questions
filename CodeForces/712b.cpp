#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin>>s;
    if(s.length()&1) {
        cout<<-1<<endl;
        return 0;
    }
    int x=0,y=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='R')
            x++;
        else if(s[i]=='L')
            x--;
        else if(s[i]=='U')
            y++;
        else
            y--;
    }
    cout<<(abs(x)+abs(y))/2<<endl;
}
