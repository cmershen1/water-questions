#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000005
ll tree[MAXN];
int n,k;
inline ll lowbit(int x) {
    return x&(-x);
}

void add(int x,int j) { //将a[x]加上j
    for(int i=x;i<=n;i+=lowbit(i)) {
        tree[i]+=j;
    }
}

ll sum(int x) { //求a[1]+...+a[x]
    ll ans=0;
    for(int i=x;i>0;i-=lowbit(i)) {
        ans+=tree[i];
    }
    return ans;
}

ll query(int i, int j) { //求a[i]+...+a[j]
    if(i>j)
        return 0;
    return sum(j)-sum(i-1);
}
    
int main() {
    while(cin >> n >> k) {
        if(k*2>n)
            k=n-k;
	    vector<ll> ans;
        memset(tree, 0, sizeof(tree));
	    ll cur=1;
	    int a=1,b=k+1;
	    for(int i=0;i<n;i++) {
	        if(a>b) {
	            ll x=query(a+1, n),y=query(1, b-1);
	            cur+=x+y+1;
	        } else {
	            ll x=query(a+1, b-1);
	            cur+=x+1;
	        }
	        ans.push_back(cur);
	        add(a,1);
	        add(b,1);
	        a=b;b=(b+k)%n;
            if(b==0)
                b=n;
	    }
	    for(int i=0;i<ans.size()-1;i++) {
	        cout << ans[i] << " ";
	    }
	    cout<<ans.back()<<endl;
    }
}
