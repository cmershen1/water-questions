#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d",&n);
    int a1=n/7*2,a2=n/7*2;
    switch (n%7) {
        case 0:break;
        case 1:a2+=1;break;
        case 2:case 3:case 4:case 5:a2+=2;break;
        case 6:a1+=1;a2+=2;break;
    }
    printf("%d %d\n", a1,a2);
}
