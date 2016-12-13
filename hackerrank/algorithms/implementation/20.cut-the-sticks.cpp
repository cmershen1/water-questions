#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1005];
int m[1005];
int main(){
    scanf("%d",&n);
    memset(m,0,sizeof(m));
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    vector<int> v;
    int sum[1000];
    for(int i=1;i<=1000;i++) {
        if(m[i])
            v.push_back(m[i]);
    }
    sum[0]=0;
    for(int i=1;i<=v.size();i++)
        sum[i]=sum[i-1]+v[i-1];
    for(int i=0;i<v.size();i++) {
        printf("%d\n", sum[v.size()]-sum[i]);
    }


}
