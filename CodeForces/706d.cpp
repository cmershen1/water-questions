#include <bits/stdc++.h>
using namespace std;

struct Trie {
  Trie* next[2];
  int cnt;
  Trie() {
    memset(next,0,sizeof(next));
    cnt=0;
  }
};
Trie* tr;
void insert(int n) {
  Trie *p=tr;
  for(int i=30;i>=0;i--) {
    int j=(n&(1<<i))?1:0;
    if(p->next[j]==NULL)
      p->next[j] = new Trie();
    p=p->next[j];
    p->cnt++;
  }
}
void del(int n) {
  Trie *p=tr;
  for(int i=30;i>=0;i--) {
    int j=(n&(1<<i))?1:0;
    p=p->next[j];
    p->cnt--;
  }
}
int query(int n) {
  int ans=0;
  Trie *p=tr;
  for(int i=30;i>=0;i--) {
    int j=(n&(1<<i))?0:1;
    if(p->next[j] && p->next[j]->cnt) {
      ans+=1<<i;
      p=p->next[j];
    }
    else {
      if(j==1)
        p=p->next[0];
      else
        p=p->next[1];
    }
  }
  return ans;
}

int main() {
  int q;
  tr = new Trie();
  insert(0);
  cin>>q;
  while(q--) {
    char c;
    int x;
    cin>>c>>x; //这个很慢！！！！
    if(c=='+')
      insert(x);
    else if(c=='-')
      del(x);
    else
      printf("%d\n", query(x));
  }
}
