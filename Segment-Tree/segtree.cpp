#include <bits/stdc++.h>

#define MAX 200005

using namespace std;

int tree[4*MAX];
int arr[MAX];
void build(int node,int st, int en)
{	
	if(st==en)
	{
		tree[node]=arr[st];
		return;
	}
	int mid = (st + en) / 2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,en);
}

int query(int node,int l,int r,int st,int en)
{
	if(r<st||l>en)
		return 0;

	if(st>=l&&en<=r)
		return tree[node];

	int mid = (st + en) / 2;
	int a=query(2*node,l,r,st,mid);
	int b=query(2*node+1,l,r,mid+1,en);
	return (a+b);	
}

void update(int node,int ind,int st,int en,int val)
{
	if(ind<st || ind>en)
		return;
	if(st==en)
	{
		arr[ind]+=val;
		tree[node]+=val;
		return;
	}
	int mid = (st + en) / 2;
	update(2*node,ind,st,mid,val);
	update(2*node+1,ind,mid+1,en,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main()
{

}
