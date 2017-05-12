#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005], b[200005], c[200005], d[200005];
int main() {
  ll n, m, k, x, s;
  scanf("%I64d %I64d %I64d %I64d %I64d", &n, &m, &k, &x, &s);
  for (int i = 0; i < m; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%I64d", &b[i]);
  }
  for (int i = 0; i < k; i++) {
    scanf("%I64d", &c[i]);
  }
  for (int i = 0; i < k; i++) {
    scanf("%I64d", &d[i]);
  }

  ll min_time = x * n;
  //只用第二种药水
  int l = 0, r = k - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (d[mid] <= s)
      l = mid;
    else
      r = mid - 1;
  }
  if (d[l] <= s)
    min_time = min(min_time, x * (n - c[l]));
  for (int i = 0; i < m; i++) {
    int l = 0, r = k - 1;
    //蓝不够用
    if (b[i] > s)
      continue;
    //只用第一种药水
    if (b[i] + d[0] > s) {
      min_time = min(min_time, a[i] * n);
      continue;
    }
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (b[i] + d[mid] <= s) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (b[i] + d[l] <= s) {
      min_time = min(min_time, a[i] * (n - c[l]));
    }
  }
  cout << min_time << endl;
}
