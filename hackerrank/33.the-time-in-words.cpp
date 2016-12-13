#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const char *num[]={"","one","two","three","four","five","six","seven","eight","nine","ten",
                "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
                "twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"};
int main(){
    int h,m;
    cin>>h>>m;
    if(m==0)
        cout<<num[h]<<" o' clock";
    else if(m==30)
        cout<<"half past "<<num[h];
    else if(m==1)
        cout<<"one minute past "<<num[h];
    else if(m==15)
        cout<<"quarter past "<<num[h];
    else if(m==45)
        cout<<"quarter to "<<num[h+1];
    else if(m==59)
        cout<<"one minute to "<<num[h+1];
    else if(m<30)
        cout<<num[m]<<" minutes past "<<num[h];
    else
        cout<<num[60-m]<<" minutes to "<<num[h+1];
}
