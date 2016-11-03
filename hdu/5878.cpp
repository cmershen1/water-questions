#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[6000];
int t,n;
int pre() {
    int i=0;
    ll cur=1;
    //2^30,3^19,5^13,7^11 > 1e9
    for(int a=0;a<=30;a++) {
        for(int b=0;b<=19;b++) {
            for(int c=0;c<=13;c++) {
                for(int d=0;d<=11;d++) {
                    cur=pow(2,a)*pow(3,b);
                    if(cur>1e9) break;
                    cur*=pow(5,c);
                    if(cur>1e9) break;
                    cur*=pow(7,d);
                    if(cur>1e9) break;
                    num[i++]=cur;
                }
            }
        }
    }
    sort(num,num+i);
    return i;
}
int main() {
    int i=pre();
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int p=lower_bound(num,num+i,n)-num;
        printf("%d\n", num[p]);
    }
}
