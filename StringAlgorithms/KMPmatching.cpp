#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int ll;
vector<int>ind;

void lpss(string x,int lps[],int n)
{
	lps[0]=0;
	int len=0,i=1;
	while(i<n)
	{
		if(x[i]==x[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
void kmp(string x,string y)
{
	int m=y.length();
	int n=x.length();
	int lps[m];
	lpss(y,lps,m);
	int i=0,j=0;
	while(i<n)
	{
		if(x[i]==y[j])
			i++,j++;
		if(j==m)
			ind.push_back(i-j),j=lps[j-1];
		else if(i<n && y[j]!=x[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}

int main()
{
 string x, y;	
	cin>>x>>y;
	kmp(x,y);
	for (int i = 0; i < ind.size(); ++i)
	{
		cout<<ind[i]<<" ";
	}
}