/*
*@author:cmershen
*@description:01背包问题模板，每件物品重量为need[i],价值为value[i],背包容量为M，每件物品只能放一次，求最大价值。
*/
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> dp(m+1,0);
    vector<int> need(n,0);
    vector<int> value(n,0);
    for(int i=0;i<n;i++) {
        cin>>need[i]>>value[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=m;j>=need[i];j--)
            if(dp[j-need[i]]+value[i]>dp[j])
                dp[j]=dp[j-need[i]]+value[i];
    }
    cout<<dp[m]<<endl;
    return 0;
}
