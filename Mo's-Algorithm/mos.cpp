// Mo's Algorithm (Square Root Decomposition)
// Preprocessing of array in O(n)
// Answers queries for Range sum in O(q*sqrt(n)+n*sqrt(n))

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long int ll;
int block;
ll array[MAX];
struct Query
{
	int l,r;
	int in;
};
Query qu[MAX];
bool comp(Query a, Query b)
{
	if(a.l/block!=b.l/block)
		return a.l/block < b.l/block;

	return a.r < b.r;
}

int main()
{

	int n,q;
	cin>>n>>q;
	
	block=sqrt(n);
	
	for (int i = 0; i < n; ++i)
	{	
		cin>>array[i];
	}

	for (int i = 0; i < q; ++i)
	{
		cin>>qu[i].l>>qu[i].r;
		qu[i].in=i;
	}
	

	sort(qu,qu+q,comp);
	

	ll sum=0;
	int lcurr=0,rcurr=0;
	ll ans[q];
	
	for (int i = 0; i < q; ++i)
	{
		int L = qu[i].l, R = qu[i].r;
		while(lcurr<L)
		{
			sum-=array[lcurr];
			lcurr++;
		}
		while(lcurr>L)
		{
			sum+=array[lcurr-1];
			lcurr--;
		}
		while(rcurr<=R)
		{
			sum+=array[rcurr];
			rcurr++;
		}
		while(rcurr>R+1)
		{
			sum-=array[rcurr-1];
			rcurr--;
		}
		ans[qu[i].in]=sum;
	}

	for (int i = 0; i < q; ++i)
	{
		cout<<ans[i]<<endl;
	}

}
