/*
*@author:cmershen
*@description:Trie树模板，求指定前缀的字符串在词典里有几个
*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include <stdio.h>
using namespace std;

#define INTMAX 2147483647
#define INTMIN -2147483648

const int max_sigma = 26;

class Node{
public:
    Node* next[max_sigma];
    int cnt;

    Node(){
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
};

class Trie : public Node {
public:
    Node *root;
    void insert(char* s){
        int c;
        Node* p = root;
        while(*s != NULL){
            c = *s - 'a';
            if(p->next[c] == NULL) {
                p->next[c] = new Node();
            }
            p = p->next[c];
            s++;
            p->cnt++;
        }
    }
    int find(char* s){
        int c;
        Node* p = root;
        while(*s != NULL){
            c = *s - 'a';
            p = p->next[c];
            if(p == NULL)
                return 0;
            s++;
        }
        return p->cnt;
    }
}t;

char word[1000002];    //word开小了，会RE！！！

int main(){
    int n,m;
    t.root=new Node();
    cin>>n;
    while(n--) {
        scanf("%s",word);
        t.insert(word);
    }
    cin>>m;
    while(m--) {
        scanf("%s",word);
        cout<<t.find(word)<<endl;
    }
    return 0;
}
