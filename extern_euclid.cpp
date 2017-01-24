/*
*@author:cmershen
*@description:扩展欧几里得算法，求乘法逆元
*/
#include <bits/stdc++.h>
const int N = 1000000007;
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
int cal(int a, int m = N) {
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

int main() {
  int n;
  scanf("%d", &n);
  printf("%d关于%d的乘法逆元是%d.\n", n, N, cal(n));
}

