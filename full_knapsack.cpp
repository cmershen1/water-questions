/*
*@author:cmershen
*@description:01背包问题模板，每件物品重量为need[i],价值为value[i],背包容量为M，每件物品可以放多次，求最大价值。
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int need[509];
int value[509];
int dp[100009];

int main()
{
    int n, m;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%d %d", &need[i], &value[i]);
    for (int i = 0; i <= m; i++)
        dp[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int v = need[i]; v <= m; v++)
        {
            if (dp[v-need[i]] + value[i] > dp[v])
                dp[v] = dp[v-need[i]] + value[i];
        }
    }
    printf ("%d\n", dp[m]);
    return 0;
}
