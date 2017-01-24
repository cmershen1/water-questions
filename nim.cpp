/**
*@author:cmershen
*@description:Nim游戏模板，A，B两人取石头子，取到最后一个的胜，A先玩，输出谁胜，石头子数是int范围的
*@source:hihocoder 1163
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int a,ans=0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d",&a);
    ans=ans^a;
  }
  if(ans)
    printf("A\n");
  else
    printf("B\n");
}
