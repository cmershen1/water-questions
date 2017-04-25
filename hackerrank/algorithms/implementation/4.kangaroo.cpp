#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if(v1==v2)
      puts(x1==x2?"YES":"NO");
    else if((x2-x1)%(v1-v2))
      puts("NO");
    else
      puts((x2-x1)%(v1-v2)>=0?"YES":"NO");
    return 0;
}
.
