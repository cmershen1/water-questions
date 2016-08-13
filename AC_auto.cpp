/*
*@author:cmershen
*@description:Trie图模板，输入一组字符串（和谐词汇）和一个长字符串（代表文章），判断文章里是否有和谐词汇
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int max_sigma = 26;

class Node{
public:
    Node* fail;
    Node* next[max_sigma];
    int cnt;

    Node(){
        memset(next, 0, sizeof(next));
        fail = NULL;
        cnt = 0;
    }
};

class AC_automato : public Node{
public:
    Node *root;
    int head, tail;

    void clear(){
        root = new Node();
        head = tail = 0;
    }

    void insert(char* s){
        int c;
        Node* p = root;
        while(*s != NULL){
            c = *s - 'a';
            if(p->next[c] == NULL) p->next[c] = new Node();
            p = p->next[c];
            s ++;
        }
        p->cnt ++;
    }

    void build(){
        root->fail = NULL;
        queue<Node* > q;
        q.push(root);

        while(!q.empty()){
            Node* tmp = q.front();
            Node* p = NULL;
            q.pop();
            for(int i=0; i<max_sigma; i++){
                if(tmp->next[i] != NULL){
                    if(tmp == root) tmp->next[i]->fail = root;
                    else{
                        p = tmp->fail;
                        while(p != NULL){
                            if(p->next[i] != NULL){
                                tmp->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if(p == NULL) tmp->next[i]->fail = root;
                    }
                    q.push(tmp->next[i]);
                }
            }
        }
    }

    int find(char* s){
        int cnt = 0, c;
        Node* p = root;
        while(*s != NULL){
            c = *s - 'a';
            while(p->next[c] == NULL && p != root)
                p = p->fail;
            p = p->next[c];
            if(p == NULL) p = root;

            Node* tmp = p;
            while(tmp != root && tmp->cnt != -1){
                cnt += tmp->cnt;
                tmp->cnt = -1;
                tmp = tmp->fail;
            }
            s ++;
        }
        return cnt;
    }
} ac;

char word[1000002];    //word开小了，会RE！！！

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        ac.clear();
        for(int i=0; i<n; i++){
            scanf("%s", word);
            ac.insert(word);
        }
        ac.build();
        scanf("%s", word);
        puts(ac.find(word) ? "YES" : "NO");
    }
    return 0;
}
