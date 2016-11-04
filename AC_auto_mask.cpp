/*
*@author:Dan__ge (modified by cmershen)
*@description:AC自动机模板，输入和谐字典，和待匹配的字符串，把字符串都和谐成星号，去掉70行的注释则变成大小写不敏感！！！
*@source:hdu 5880
*/

#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000010;
int ans[maxn],cnt[maxn];
struct Trie{
    int next[maxn][26],fail[maxn],end[maxn];
    int root,L,ko;
    int newnode(){
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init(){
        L = 0,ko=0;
        root = newnode();
        memset(ans,0,sizeof(ans));
    }
    void insert(char buf[]){
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++){
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        if(end[now]==0){
            ko++;end[now]=ko;
            cnt[ko]=len;
        }else{
            if(cnt[end[now]]<len) cnt[end[now]]=len;
        }
    }
    void build(){
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1) next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() ){
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void query(char buf[]){
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++){
            if(buf[i]>='a'&&buf[i]<='z') now = next[now][buf[i]-'a'];
            //else if(buf[i]>='A'&&buf[i]<='Z') now = next[now][buf[i]-'A'];
            else continue;
            int temp = now;
            while( temp != root ){
                ans[i+1]--;ans[i-cnt[end[temp]]+1]++;
                temp = fail[temp];
            }
        }
    }
};
char buf[maxn];
Trie ac;
int main(){
    int T,n;
    scanf("%d",&T);
    while( T-- ){
        scanf("%d",&n);
        ac.init();
        for(int i = 0;i < n;i++){
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        getchar();
        gets(buf);
        ac.query(buf);
        int len=strlen(buf),sum=0;
        for(int i=0;i<len;i++){
            sum+=ans[i];
            if(sum<=0) printf("%c",buf[i]);
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}
