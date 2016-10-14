#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(string s) {
    if(s=="sunday")
        return 0;
    else if(s=="monday")
        return 1;
    else if(s=="tuesday")
        return 2;
    else if(s=="wednesday")
        return 3;
    else if(s=="thursday")
        return 4;
    else if(s=="friday")
        return 5;
    else
        return 6;

}
int main() {
    char s1[10],s2[10];
    gets(s1);
    gets(s2);
    cout<<f(s1)<<","<<f(s2)<<endl;
    int s=f(s1)-f(s2);
    if(s==0 || s==2 ||s==-5 || s==3 || s==-4)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
