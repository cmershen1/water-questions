#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string p[105];
string password;
int len[105];
int main() {
    memset(len,0,sizeof(len));
    scanf("%d %d\n",&n,&k);
    for(int i=0;i<n;i++) {
        cin>>p[i];
        len[p[i].length()]++;
    }

    cin>>password;
    int passLength = password.length();

    int cnt=0;
    for(int i=1;i<passLength;i++)
        cnt+=len[i];

    int minTimes=cnt+1 , maxTimes = cnt+len[passLength];
    int minSec = minTimes + (minTimes-1)/k*5,maxSec = maxTimes+(maxTimes-1)/k*5;
    printf("%d %d\n", minSec,maxSec);
}
