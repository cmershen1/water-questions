#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int rev(int i) {
    int r=0;
    while(i) {
        r*=10;
        r+=i%10;
        i/=10;
    }
    return r;
}
int main(){
    int i,j,k,cnt=0;
    scanf("%d %d %d",&i,&j,&k);
    while(i<=j) {
        if(abs(i-rev(i++))%k==0)
            cnt++;

    }
    printf("%d\n",cnt );

}
