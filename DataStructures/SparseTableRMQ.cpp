//Sparse Table RMQ
//NLogN Preprocessing O(1) Query

#include<bits/stdc++.h>

using namespace std; 
int a[100005];
int b[100005][20];
int main()
{
	int tc;
	scanf("%d",&tc);
	for (int t = 1; t <=tc ; ++t)
	{
		printf("Case %d:\n",t);

		int n,q,l,r;
		
		scanf("%d %d",&n,&q);
		
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		for (int i = 0; i <n ; ++i)
		{
			b[i][0]=i;
		}
		//preprocess
		for (int j = 1; (1<<j) <=n ; j++)
		{
			for (int i = 0; i+(1<<j)-1 <n ; ++i)
			{
				if(a[b[i][j-1]]<a[b[i+(1<<(j-1))][j-1]])
					b[i][j]=b[i][j-1];
				else
					b[i][j]=b[i+(1<<(j-1))][j-1];
			}
		}
		//query
		for (int i = 0; i < q; ++i)
		{
			
			scanf("%d %d",&l,&r);
			l--;
			r--;
			int len=log2(r-l+1);
			printf("%d\n",min(a[b[l][len]],a[b[r-(int)pow(2,len)+1][len]]));
		}
	}
}
