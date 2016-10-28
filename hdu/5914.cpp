//source:2016中国大学生程序设计竞赛（长春）
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int fib[8]={1,1,2,3,5,8,13,21};
int solve() {
    int i=0;
    while(fib[i]<=n)
        i++;
    return n-i+1;
}
int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        printf("Case #%d: %d\n", i,solve());
    }
}
