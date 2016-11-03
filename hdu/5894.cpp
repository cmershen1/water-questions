#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+7;
ll pre[1000005];
int t;
ll n,m,k;
int egcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int ans = egcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return ans;
}
int cal(int a, int m) {//求乘法逆元，即求x 使得ax % M = 1
  int x, y;
  int gcd = egcd(a, m, x, y);
  if (1 % gcd != 0)
    return -1;
  x *= 1 / gcd;
  m = abs(m);
  int ans = x % m;
  if (ans <= 0)
    ans += m;
  return ans;
}
long long qmod( long long a, long long b, long long mod ) {//快速计算 (a*b) % mod

    long long ans = 0;  // 初始化
    while(b)                //根据b的每一位看加不加当前a
    {
        if(b & 1)           //如果当前位为1
        {
            b--;
            ans =(ans+ a)%mod;   //ans+=a
        }
        b /= 2;                         //b向前移位
        a = (a + a) % mod;          //更新a

    }
    return ans;
}
void init() { //预处理1~1e6的阶乘对M的逆元
    pre[1]=1;
    for(int i=2;i<=1e6;i++)
        pre[i]=(pre[i-1]*i)%M;
    for(int i=1;i<=1e6;i++)
        pre[i]=cal(pre[i],M);
}
int main() {
    init();
    scanf("%d",&t);
    while (t--) {
        scanf("%I64d %I64d %I64d",&n,&m,&k);
        if(m==1) {
            printf("%lld\n",n);
            continue;
        }
        if(n-m*k<m) {
            printf("0\n");
            continue;
        }
        ll a = 1;
        for(int i=1;i<m;i++) {
            //cout<<i<<endl;
            a=(qmod(a,(n-m*k-i),M))%M;
        }
        a=(a*n)%M;
        a=(a*pre[m])%M;
        printf("%I64d\n", a%M);
    }
}
