#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int a[30];
    char w[11];
    for(int i=0;i<26;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%s",w);
    int m=-1;
    for(int i=0;w[i];i++) {
        m=max(m,a[w[i]-'a']);
    }
    printf("%d\n", m*strlen(w));
}
