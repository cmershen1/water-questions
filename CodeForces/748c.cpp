#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    string s;
    while(cin>>n>>s) {
        int cnt=1;
        int start_x=0,start_y=0,cur_x=0,cur_y=0,dis=0,max_dis=0;
        for(int i=0;i<n;i++) {
            int last_x=cur_x,last_y=cur_y;
            if(s[i]=='R')
                cur_x++;
            else if(s[i]=='U')
                cur_y++;
            else if(s[i]=='L')
                cur_x--;
            else if(s[i]=='D')
                cur_y--;
            dis=abs(cur_x-start_x)+abs(cur_y-start_y);
            if(dis>max_dis)
                max_dis=dis;
            else if(dis<max_dis) {
                //cout<<i<<endl;
                start_x=last_x;
                start_y=last_y;
                dis=max_dis=1;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
