/*
*@author:cmershen
*@description:线段树模板，动态更新求区间最小值问题(单点更新)
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int const N=1000010;

struct segtree
{
	int left,right;
	int val;
}t[4*N];
int n,q;

void build(int cur,int l,int r)
{
	t[cur].left=l;
	t[cur].right=r;
	if (l == r) scanf("%d",&t[cur].val);
	else
	{
		int L=cur<<1,R=cur<<1|1;
		int m=(l+r)>>1;
		build(L,l,m);
		build(R,m+1,r);
		t[cur].val=min(t[L].val,t[R].val);
	}
}

void update(int cur,int i,int val)
{
	if (t[cur].left == t[cur].right)
	{
		t[cur].val=val;
		return;
	}
	int L=cur<<1,R=cur<<1|1;
	int m=(t[cur].left+t[cur].right)>>1;

	if (i<=m) update(L,i,val);
	else update(R,i,val);

	t[cur].val=min(t[L].val,t[R].val);
}

int query(int cur,int l,int r)
{
	if (t[cur].left>=l && t[cur].right<=r) return t[cur].val;

	int L=cur<<1,R=cur<<1|1;
	int m=(t[cur].left+t[cur].right)>>1;

	if (r<=m) return query(L,l,r);
	else if (l>m) return query(R,l,r);
	else return min(query(L,l,r),query(R,l,r));
}

int main()
{
	//freopen("in","r",stdin);
	cin>>n;
	build(1,1,n);

	cin>>q;
	while (q--)
	{
		int c,a,b;
		scanf("%d%d%d",&c,&a,&b);
		if (c) update(1,a,b);
		else printf("%d\n",query(1,a,b));
	}

}
