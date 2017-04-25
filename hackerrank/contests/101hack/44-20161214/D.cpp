#include <bits/stdc++.h>
using namespace std;

#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define eps 1e-8

#define LEFT idx<<1,begin,mid
#define RIGHT idx<<1|1,mid+1,end

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;

const int M = 1e9 + 7;
const double PI = acos(-1.0);

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 6;

int n,q;
char s[123456];
struct node {
    int lazy;
    int cnt[30];
}segtree[1<<18],id;

ll qmod(ll a,ll b,ll c) {
	ll ans=1;
	a=a%c;
	while(b>0) {
		if(b&1)
			ans=(ans*a)%c;
		b=b/2;
		a=(a*a)%c;
	}
	return ans;
}

node merge(node a,node b) {
    node c;
    c.lazy=0;
    for(int i=0;i<26;i++) {
        c.cnt[i]=a.cnt[(i+a.lazy)%26]+b.cnt[(i+b.lazy)%26];
    }
    return c;
}

void apply(int a,int b) {
    segtree[a].lazy+=b;
}

void down(int x) {
    if(segtree[x].lazy) {
        apply(x*2, segtree[x].lazy);
        apply(x*2+1, segtree[x].lazy);
        node c;
        c.lazy=0;
        for(int i=0;i<26;i++) 
            c.cnt[i]=segtree[x].cnt[(i+segtree[x].lazy)%26];
        segtree[x]=c;
    }
}

void build(int idx,int begin,int end) {
    if(begin==end)
        segtree[idx].cnt[s[begin-1]-'a']++;
    else {
        int mid=(begin+end)/2;
        build(LEFT);
        build(RIGHT);
        segtree[idx]=merge(segtree[idx*2],segtree[idx*2+1]);
    }
}

void update(int idx,int begin,int end,int l,int r,int v) {
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
        apply(idx,v);
    else {
        down(idx);
        int mid=(begin+end)/2;
        update(LEFT,l,r,v);
        update(RIGHT,l,r,v);
        segtree[idx]=merge(segtree[idx*2],segtree[idx*2+1]);
    }
}

node query(int idx,int begin,int end,int l,int r) {
    if(r<begin || end<l)
        return id;
    if(l<=begin && end<=r)
        return segtree[idx];
    else {
        down(idx);
        int mid=(begin+end)/2;
        node a=query(LEFT,l,r);
        node b=query(RIGHT,l,r);
        return merge(a,b);
    }
}

void shift(int i,int j,int t) {
    update(1,1,n,i+1,j+1,(26-(t%26))%26);
}

ll solve(int x,int y) {
    ll pre[27],suf[27],even[27],odd[27];
    for(int i=0;i<27;i++) {
        pre[i]=0;suf[i]=0;even[i]=0;odd[i]=0;
    }
<<<<<<< HEAD
    node d=query(1,1,n,x+1,y+1);//得到结果节点
=======
    node d=query(1,1,n,x+1,y+1);
>>>>>>> c3bc45e0265d2a23d3dc1f76e4b01a98c74f8382
    for(int i=0;i<26;i++) {
        int c=d.cnt[i];
        if(c==0) {
            even[i]=1;
            odd[i]=0;
        }
        else {
<<<<<<< HEAD
            even[i]=odd[i]=qmod(2,c-1,M);//直接用1<<(c-1)肯定会爆ll
=======
            even[i]=odd[i]=qmod(2,c-1,M);
>>>>>>> c3bc45e0265d2a23d3dc1f76e4b01a98c74f8382
        }
    }
    pre[0]=1;suf[26]=1;
    for(int i=1;i<=26;i++)
        pre[i]=(pre[i-1]*even[i-1])%M;
    for(int i=25;i>=0;i--)
        suf[i]=(suf[i+1]*even[i])%M;
<<<<<<< HEAD
    ll ans=suf[0];//不考虑奇数个字母的出现，答案为(even[0]*...*even[25])%M
=======
    ll ans=suf[0];
>>>>>>> c3bc45e0265d2a23d3dc1f76e4b01a98c74f8382

    for(int i=0;i<26;i++) {
        ll temp=(pre[i]*odd[i])%M;
        temp=(temp*suf[i+1])%M;
        ans=(ans+temp)%M;
    }
    return ans-1;

}

int main() {
<<<<<<< HEAD
    RE("in.txt");WR("out.txt");
=======
    //RE("in.txt");WR("out.txt");
>>>>>>> c3bc45e0265d2a23d3dc1f76e4b01a98c74f8382
    cin>>n>>q;
    cin>>s;
    // cout<<n<<" "<<q<<endl;
    // cout<<s<<endl;
    build(1,1,n);
    while(q--) {
        int op,x,y,t;
        cin>>op;
        if(op==1) {
            cin>>x>>y>>t;
            shift(x,y,t);
        }
        else {
            cin>>x>>y;
            cout<<solve(x,y)<<endl;
        }
    } 
}
