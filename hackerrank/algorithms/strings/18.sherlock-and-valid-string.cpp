#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m[26];
int main(){
    string s;
    cin>>s;
    memset(m,0,sizeof(m));
    for(int i=0;i<s.length();i++) {
        m[s[i]-'a']++;
    }
    map<int,int> freq;
    for(int i=0;i<26;i++) {
        if(m[i])
            freq[m[i]]++;
    }
    if(freq.size()>2)
        cout<<"NO"<<endl;
    else if(freq.size()==2) {
        int a,b;
        for(map<int,int>::iterator i=freq.begin();i!=freq.end();i++) {
            if(i==freq.begin())
                a=i->second;
            else
                b=i->second;
        }
        if(a==1 || b==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"YES"<<endl;
}
