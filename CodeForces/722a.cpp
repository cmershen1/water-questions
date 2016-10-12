#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
int main() {
    scanf("%d",&n);
    scanf("%d:%d",&a,&b);
    if(n==12) {
        if(a==0)
            a=1;
        if(a>12) {
            if(a%10==0)
                a=10;
            else
                a=a%10;
        }

        if(b>59)
            b=b%10;
    }
    else {
        // if(a==0)
        //     a=1;
        if(a>23)  {
            if(a%10==0)
                a=10;
            else
                a=a%10;
        }

        if(b>59)
            b=b%10;
    }
    printf("%02d:%02d\n", a,b);
}
