#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++) {
        sum1+=a[i][i];
        sum2+=a[i][n-1-i];
    }
    printf("%d\n", abs(sum1-sum2));
}
