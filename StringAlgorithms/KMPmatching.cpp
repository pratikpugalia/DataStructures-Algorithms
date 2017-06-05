#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int ll;
vector<int>ind;

void lpss(string x,int lps[],int n) // LPS Array calculation essential for KMP
{
	lps[0]=0;
	int len=0,i=1;
	while(i<n)
	{
		if(x[i]==x[len]) // If it matches increase length of suffix that matches prefix till i and increment i
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1]; //jump to last computed index value 
			}
			else
			{
				lps[i]=0; //After entire check no matches found hence 0 
				i++;
			}
		}
	}
}
void kmp(string x,string y)
{
	int m=y.length(),n=x.length();
	int lps[m];
	lpss(y,lps,m);
	for(int i=0;i<m;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	int i=0,j=0;
	while(i<n)
	{
		if(x[i]==y[j]) //For match increment both the indices
			i++,j++;

		if(j==m)
			ind.push_back(i-j),j=lps[j-1]; //if j is equal to pattern length MATCH FOUND at index i-j 
						       //and reset skipping the starting largest prefix that are also suffix
		else if(i<n && y[j]!=x[i])
		{
			if(j!=0)
				j=lps[j-1]; //looking for point to find a positive match
			else
				i++;       //match not possible increment i
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
