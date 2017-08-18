#include <bits/stdc++.h>

using namespace std;
#define MAX 1000005
int sp[MAX];
vector< pair<int,int> > ans;

void sieve() //O(nlog(log n))
{
	for (int i = 2; i <MAX; ++i)
	{
		if(!sp[i])
		{
			sp[i]=i;
			for (int j = 2*i; j <MAX; j+=i)
			{
				if(sp[j]==0)
				sp[j]=i;
			}
		}
	}
}

void prime_factorize(int a)// ~= O(log(n))
{
	if(a<=1)return;
	while(1)
	{
		int div=sp[a];
		int count=0;
		while(!(a%div))
		{
			a/=div;
			count++;
		}
		ans.push_back(make_pair(div,count));
		if(a<=1)
			break;
	}
}


int main()
{
	int a;cin>>a;
	sieve();
	prime_factorize(a);
	for (int i = 0; i <ans.size(); ++i)
	{
		cout<<"exponent,power : "<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}