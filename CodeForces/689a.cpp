#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;char d[10];
  int cnt[10];
  memset(cnt,0,sizeof(cnt));
  scanf("%d", &n);
  scanf("%s", d);
  for(int i=0;i<n;i++)
    cnt[d[i]-'0']++;
  if((cnt[1]&&cnt[9])||(cnt[1]&&cnt[0])||(cnt[3]&&cnt[7])||(cnt[3]&&cnt[0])||(cnt[3]&&cnt[4]&&cnt[9])||(cnt[1]&&cnt[6]&&cnt[7])||(cnt[2]&&cnt[7]&&cnt[9])||(cnt[2]&&cnt[6]&&cnt[7])||(cnt[2]&&cnt[4]&&cnt[9])||(cnt[2]&&cnt[0]))
    printf("YES");
  else
    printf("NO");
}
