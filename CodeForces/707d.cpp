#include <bits/stdc++.h>
using namespace std;
struct node {
  int op,i,j;//每次操作的操作数
  int ans;//当前节点中书的数目
};
node p[100005];
bool book[1005][1005];
vector<int> g[100005];//邻接表
int n,m,q;
void dfs(int t,int cur) {
  p[t].ans=cur;
  for(int i=0;i<g[t].size();i++) {
    int next=g[t][i];
    if(p[next].op==1) {
      if(book[p[next].i][p[next].j]) {//操作1下如果有书则书架不变
        dfs(next,cur);
      }
      else {
        book[p[next].i][p[next].j]=true;
        dfs(next,cur+1);
        book[p[next].i][p[next].j]=false;//回溯，保持书架情况与当前节点一致
      }
    }
    else if(p[next].op==2) {
      if(!book[p[next].i][p[next].j]) {
        dfs(next,cur);
      }
      else {
        book[p[next].i][p[next].j]=false;
        dfs(next,cur-1);
        book[p[next].i][p[next].j]=true;
      }
    }
    else if(p[next].op==3) {
      int change=0;//要改变的书本数目
      for(int j=1;j<=m;j++) {
        if(book[p[next].i][j]) {
          book[p[next].i][j]=false;
          change--;
        }
        else {
          book[p[next].i][j]=true;
          change++;
        }
      }
      dfs(next,cur+change);
      for(int j=1;j<=m;j++)
        book[p[next].i][j]=!book[p[next].i][j];
    }
    else {
      dfs(next,cur); //跳转不改变书本数量
    }
  }
}
int main() {
  memset(book,false,sizeof(book));
  p[0].ans=0;
  scanf("%d %d %d", &n,&m,&q);
  for(int i=1;i<=q;i++) {
    scanf("%d", &p[i].op);
    if(p[i].op==1 || p[i].op==2) {
      g[i-1].push_back(i);//向下顺序建树
      scanf("%d %d", &p[i].i,&p[i].j);
    }
    else if(p[i].op==3) {
      g[i-1].push_back(i);
      scanf("%d", &p[i].i);
    }
    else {
      scanf("%d", &p[i].i);
      g[p[i].i].push_back(i);//要退回的节点增加一个孩子
    }
  }
  dfs(0,0);//0号节点为根节点，有0本书
  for(int i=1;i<=q;i++)
    printf("%d\n", p[i].ans);
}
